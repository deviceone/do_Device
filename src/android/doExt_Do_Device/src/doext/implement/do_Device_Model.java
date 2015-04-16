package doext.implement;

import android.app.Activity;
import android.content.Context;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.hardware.Camera.Parameters;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.os.Vibrator;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.view.WindowManager;
import core.DoServiceContainer;
import core.helper.DoTextHelper;
import core.helper.jsonparse.DoJsonNode;
import core.interfaces.DoIScriptEngine;
import core.object.DoInvokeResult;
import core.object.DoSingletonModule;
import doext.define.do_Device_IMethod;

/**
 * 自定义扩展SM组件Model实现，继承DoSingletonModule抽象类，并实现Do_Device_IMethod接口方法；
 * #如何调用组件自定义事件？可以通过如下方法触发事件：
 * this.model.getEventCenter().fireEvent(_messageName, jsonResult);
 * 参数解释：@_messageName字符串事件名称，@jsonResult传递事件参数对象；
 * 获取DoInvokeResult对象方式new DoInvokeResult(this.model.getUniqueKey());
 */
public class do_Device_Model extends DoSingletonModule implements do_Device_IMethod{

	public do_Device_Model() throws Exception {
		super();
	}
	
	/**
	 * 同步方法，JS脚本调用该组件对象方法时会被调用，可以根据_methodName调用相应的接口实现方法；
	 * @_methodName 方法名称
	 * @_dictParas 参数（K,V）
	 * @_scriptEngine 当前Page JS上下文环境对象
	 * @_invokeResult 用于返回方法结果对象
	 */
	@Override
	public boolean invokeSyncMethod(String _methodName, DoJsonNode _dictParas,
			DoIScriptEngine _scriptEngine, DoInvokeResult _invokeResult)
			throws Exception {
		if ("vibrate".equals(_methodName)) {
			vibrate(_dictParas, _scriptEngine, _invokeResult);
			return true;
		}
		if ("beep".equals(_methodName)) {
			beep(_dictParas, _scriptEngine, _invokeResult);
			return true;
		}
		if ("flash".equals(_methodName)) {
			flash(_dictParas, _scriptEngine, _invokeResult);
			return true;
		}
		if ("getInfo".equals(_methodName)) {
			getInfo(_dictParas, _scriptEngine, _invokeResult);
			return true;
		}
		return super.invokeSyncMethod(_methodName, _dictParas, _scriptEngine, _invokeResult);
	}
	
	/**
	 * 异步方法（通常都处理些耗时操作，避免UI线程阻塞），JS脚本调用该组件对象方法时会被调用，
	 * 可以根据_methodName调用相应的接口实现方法；
	 * @throws Exception 
	 * @_methodName 方法名称
	 * @_dictParas 参数（K,V）
	 * @_scriptEngine 当前page JS上下文环境
	 * @_callbackFuncName 回调函数名
	 * #如何执行异步方法回调？可以通过如下方法：
	 * _scriptEngine.callback(_callbackFuncName, _invokeResult);
	 * 参数解释：@_callbackFuncName回调函数名，@_invokeResult传递回调函数参数对象；
	 * 获取DoInvokeResult对象方式new DoInvokeResult(this.model.getUniqueKey());
	 */
	@Override
	public boolean invokeAsyncMethod(String _methodName, DoJsonNode _dictParas,
			DoIScriptEngine _scriptEngine, String _callbackFuncName) throws Exception {
		//...do something
		return super.invokeAsyncMethod(_methodName, _dictParas, _scriptEngine, _callbackFuncName);
	}

	/**
	 * 短音提示；
	 * @_dictParas 参数（K,V），可以通过此对象提供相关方法来获取参数值（Key：为参数名称）；
	 * @_scriptEngine 当前Page JS上下文环境对象
	 * @_invokeResult 用于返回方法结果对象
	 */
	@Override
	public void beep(DoJsonNode _dictParas, DoIScriptEngine _scriptEngine,
			DoInvokeResult _invokeResult) throws Exception {
		Ringtone alertRingtone = getRingtone(DoServiceContainer.getPageViewFactory().getAppContext());
		if (alertRingtone != null && !alertRingtone.isPlaying()) {
			alertRingtone.play();
		}
	}

	/**
	 * 开关闪光灯；
	 * @_dictParas 参数（K,V），可以通过此对象提供相关方法来获取参数值（Key：为参数名称）；
	 * @_scriptEngine 当前Page JS上下文环境对象
	 * @_invokeResult 用于返回方法结果对象
	 */
	@Override
	public void flash(DoJsonNode _dictParas, DoIScriptEngine _scriptEngine,
			DoInvokeResult _invokeResult) throws Exception {
		String _status = _dictParas.getOneText("status", "");
		if (null != _status && "on".equals(_status)) {
			if (camera == null) {
				camera = Camera.open();
			}
			if (!isopen) {
				// 开始亮灯。通过setFlashMode()及startPreview()两种方式确保亮灯。
				Parameters params = camera.getParameters();
				params.setFlashMode(Parameters.FLASH_MODE_TORCH);
				camera.setParameters(params);
				camera.setPreviewTexture(new SurfaceTexture(0));
				camera.startPreview(); 
				isopen = true;
			}
		} else if (null != _status && "off".equals(_status)) {
			if (camera != null) {
				// 灭灯。通过setFlashMode()及stopPreview()两种方式确保灭灯。
				Parameters params = camera.getParameters();
				params.setFlashMode(Parameters.FLASH_MODE_OFF);
                camera.setParameters(params);
				camera.stopPreview(); 
				camera.release(); // 关掉照相机
				camera = null;
				isopen = false;
			}
		}
	}

	/**
	 * 设备振动；
	 * @_dictParas 参数（K,V），可以通过此对象提供相关方法来获取参数值（Key：为参数名称）；
	 * @_scriptEngine 当前Page JS上下文环境对象
	 * @_invokeResult 用于返回方法结果对象
	 */
	@Override
	public void vibrate(DoJsonNode _dictParas, DoIScriptEngine _scriptEngine,
			DoInvokeResult _invokeResult) throws Exception {
		int _duration = DoTextHelper.strToInt(_dictParas.getOneText("duration", ""), 1000);
		Vibrator _vibrator = (Vibrator) DoServiceContainer.getPageViewFactory().getAppContext().getSystemService(Context.VIBRATOR_SERVICE);
		_vibrator.vibrate(_duration);
	}

	/**
	 * 获取设备信息；
	 * @_dictParas 参数（K,V），可以通过此对象提供相关方法来获取参数值（Key：为参数名称）；
	 * @_scriptEngine 当前Page JS上下文环境对象
	 * @_invokeResult 用于返回方法结果对象
	 */
	@Override
	public void getInfo(DoJsonNode _dictParas, DoIScriptEngine _scriptEngine,
			DoInvokeResult _invokeResult) throws Exception {
		Context _ctx = DoServiceContainer.getPageViewFactory().getAppContext();
		TelephonyManager _tm = (TelephonyManager) _ctx.getSystemService(Context.TELEPHONY_SERVICE);
		DisplayMetrics _dm = _ctx.getResources().getDisplayMetrics();
		WindowManager _wm = (WindowManager) _ctx.getSystemService(Context.WINDOW_SERVICE);

		DoJsonNode _node = new DoJsonNode();
		_node.setOneText("deviceId", _tm.getDeviceId());
		_node.setOneText("deviceName", android.os.Build.MODEL);
		_node.setOneText("OS", "android");
		_node.setOneText("OSVersion", android.os.Build.VERSION.RELEASE);
		_node.setOneText("resolutionH", _dm.widthPixels + "");
		_node.setOneText("resolutionV", _dm.heightPixels + "");
		_node.setOneText("dpiH", _dm.xdpi + "");
		_node.setOneText("dpiV", _dm.ydpi + "");
		_node.setOneText("screenH", _wm.getDefaultDisplay().getWidth() + "");
		_node.setOneText("screenV", _wm.getDefaultDisplay().getHeight() + "");
		_node.setOneText("phoneType", _tm.getPhoneType() + "");
		_node.setOneText("phoneNumber", _tm.getLine1Number());
		_node.setOneText("communicationtype", _tm.getNetworkOperatorName());
		_node.setOneText("simSerialNumber", _tm.getSimSerialNumber());
		_node.setOneText("IMSI", _tm.getSubscriberId());
		_node.setOneText("sdkVersion", android.os.Build.VERSION.SDK);
		_invokeResult.setResultNode(_node);
	}
	
	private Ringtone alertRingtone;

	private Ringtone getRingtone(Activity activity) {
		if (alertRingtone == null) {
			alertRingtone = RingtoneManager.getRingtone(activity, RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION));
		}
		return alertRingtone;
	}

	public void releaseRingtong() {
		if (alertRingtone != null) {
			alertRingtone.stop();
			alertRingtone = null;
		}
	}

	private Camera camera = null;
	private boolean isopen = false;
}
