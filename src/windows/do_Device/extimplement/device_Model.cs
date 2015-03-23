using doCore.Helper.JsonParse;
using doCore.Interface;
using doCore.Object;
using do_Device.extdefine;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using doCore.Helper;
using Windows.Graphics.Display;
using Windows.Data.Json;
using Windows.UI.Xaml;
using doCore;
using Windows.UI.Xaml.Controls;
using Windows.Security.ExchangeActiveSyncProvisioning;

namespace do_Device.extimplement
{
    /// <summary>
    /// 自定义扩展API组件Model实现，继承DoSingletonModule抽象类，并实现@TYPEID_IMethod接口方法；
    /// #如何调用组件自定义事件？可以通过如下方法触发事件：
    /// this.model.getEventCenter().fireEvent(_messageName, jsonResult);
    /// 参数解释：@_messageName字符串事件名称，@jsonResult传递事件参数对象；
    /// 获取DoInvokeResult对象方式this.model.getCurrentPage().getScriptEngine().createInvokeResult(model.getUniqueKey());
    /// </summary>
    public class device_Model : doSingletonModule, device_IMethod
    {
        public device_Model()
            : base()
        {

        }
        /// <summary>
        /// 同步方法，JS脚本调用该组件对象方法时会被调用，可以根据_methodName调用相应的接口实现方法；
        /// </summary>
        /// <param name="_methodName">方法名称</param>
        /// <param name="_dictParas">参数（K,V）</param>
        /// <param name="_scriptEngine">当前Page JS上下文环境对象</param>
        /// <param name="_invokeResult">用于返回方法结果对象</param>
        /// <returns></returns>
        public override bool InvokeSyncMethod(string _methodName, doCore.Helper.JsonParse.doJsonNode _dictParas, doCore.Interface.doIScriptEngine _scriptEngine, doInvokeResult _invokeResult)
        {
			if ("beep".Equals(_methodName)){this.beep(_dictParas, _scriptEngine, _invokeResult);return true;}
			if ("flash".Equals(_methodName)){this.flash(_dictParas, _scriptEngine, _invokeResult);return true;}
			if ("getInfo".Equals(_methodName)){this.getInfo(_dictParas, _scriptEngine, _invokeResult);return true;}
			if ("vibrate".Equals(_methodName)){this.vibrate(_dictParas, _scriptEngine, _invokeResult);return true;}

            return base.InvokeSyncMethod(_methodName, _dictParas, _scriptEngine, _invokeResult);
        }
        private void vibrate(doJsonNode _dictParas, doIScriptEngine _scriptEngine, doInvokeResult _invokeResult)
        {
            try
            {
                if (doMyTools.lsSync.ContainsKey("vibration"))
                {
                    doMyTools.lsSync["vibration"].FuncDo(null);
                }
            }
            catch (Exception _err)
            {
                doServiceContainer.LogEngine.WriteError("doDevice vibrate \n", _err);
            }
        }
        private async void beep(doJsonNode _dictParas, doIScriptEngine _scriptEngine, doInvokeResult _invokeResult)
        {
            try
            {
                MediaElement me = new MediaElement();
                var file = await Windows.Storage.StorageFile.GetFileFromApplicationUriAsync(new Uri("ms-appx:///doBase/Resource/aa.mp3"));
                var stream = await file.OpenReadAsync();
                me.SetSource(stream, "");
                me.Play();
            }
            catch (Exception _err)
            {
                doServiceContainer.LogEngine.WriteError("doDevice beep \n", _err);
            }
        }
        private void flash(doJsonNode _dictParas, doIScriptEngine _scriptEngine, doInvokeResult _invokeResult)
        {
            try
            {
                string format = _dictParas.GetOneText("status", "");
                if (format == "on")
                {
                    doCore.Helper.doCaptureOperator.OpenTorch();
                }
                else
                {
                    doCore.Helper.doCaptureOperator.CloseTorch();
                }
            }
            catch (Exception _err)
            {
                doServiceContainer.LogEngine.WriteError("doDevice flash \n", _err);
            }
        }
        private void getInfo(doJsonNode _dictParas, doIScriptEngine _scriptEngine, doInvokeResult _invokeResult)
        {
            try
            {
                doJsonNode jn = new doJsonNode();
                JsonObject jo = doMyTools.lsSync["resolution"].FuncDo(null) as JsonObject;
                var bounds = Window.Current.Bounds;
                //设备ID(IMEI)(GSM手机的 IMEI 和 CDMA手机的 MEID,ios的uuid，phone8 根据开发者获取唯一id). 
                jn.SetOneText("deviceId", doMyTools.getdeviceid());
                //deviceName：设备名称
                jn.SetOneText("deviceName", doMyTools.getdevicename());
                //OS：操作系统版本
                jn.SetOneText("OS", doMyTools.EnvironmentOs);
                //OSVersion：操作系统版本号
                jn.SetOneText("OS", "8.1");
                //resolutionH：水平分辨率
                jn.SetOneText("resolutionH", jo.GetNamedString("resolutionH"));
                //resolutionV：垂直分辨率
                jn.SetOneText("resolutionV", jo.GetNamedString("resolutionV"));
                //dpiH：水平像素密度
                jn.SetOneText("dpiH", DisplayInformation.GetForCurrentView().RawDpiX.ToString());
                //dpiV：垂直像素密度
                jn.SetOneText("dpiV", DisplayInformation.GetForCurrentView().RawDpiY.ToString());
                //screenH：水平屏幕宽度（dip)
                jn.SetOneText("screenH", bounds.Width.ToString());
                //screenV：垂直屏幕宽度（dip)
                jn.SetOneText("screenV", bounds.Height.ToString());
                //phoneType：手机机型（GT-15908）
                jn.SetOneText("phoneType", getdevicetype());
                //phoneNumber：手机号码
                //jn.SetOneText("phoneNumber", "");
                //communicationType：运营商类型
                //simSerialNumber：SIM卡的序列号
                //jn.SetOneText("simSerialNumber", "");
                //IMSI：IMSI(国际移动用户识别码)
                //jn.SetOneText("IMSI", "");
                //sdkVersion：获取手机内存大小
                //jn.SetOneText("sdkVersion", "8");
                if (_dictParas.GetOneText("name", "") == "all" || string.IsNullOrEmpty(_dictParas.GetOneText("name", "")))
                {
                    _invokeResult.SetResultNode(jn);
                }
                else
                {
                    string data = jn.GetOneText(_dictParas.GetOneText("name", ""), "");
                    _invokeResult.SetResultText(data);
                }
            }
            catch (Exception _err)
            {
                doServiceContainer.LogEngine.WriteError("doDevice getInfo \n", _err);
            }
        }
        public  string getdevicetype()
        {
            EasClientDeviceInformation easClientDeviceInformation = new EasClientDeviceInformation();
            return easClientDeviceInformation.FriendlyName;
        }
        /// <summary>
        /// 异步方法（通常都处理些耗时操作，避免UI线程阻塞），JS脚本调用该组件对象方法时会被调用，
        /// 可以根据_methodName调用相应的接口实现方法；
        /// </summary>
        /// <param name="_methodName">方法名称</param>
        /// <param name="_dictParas">参数（K,V）</param>
        /// <param name="_scriptEngine">当前page JS上下文环境</param>
        /// <param name="_callbackFuncName">回调函数名</param>
        /// <returns></returns>
        public override async Task<bool> InvokeAsyncMethod(string _methodName, doCore.Helper.JsonParse.doJsonNode _dictParas, doCore.Interface.doIScriptEngine _scriptEngine, string _callbackFuncName)
        {
            doInvokeResult _invokeResult = new doInvokeResult(this.UniqueKey);

            return await base.InvokeAsyncMethod(_methodName, _dictParas, _scriptEngine, _callbackFuncName);
        }
    
    }
}
