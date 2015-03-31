//
//  Do_MyDevice_SM.m
//  DoExt_SM
//
//  Created by @userName on @time.
//  Copyright (c) 2015年 DoExt. All rights reserved.
//

#import "do_Device_SM.h"

#import "doScriptEngineHelper.h"
#import "doIScriptEngine.h"
#import "doInvokeResult.h"
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import  <CoreTelephony/CTCarrier.h>
#import  <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <UIKit/UIKit.h>
#import "doJsonNode.h"

@implementation do_Device_SM
{
    BOOL isLigthOn;
    AVCaptureDevice *device;
}
#pragma mark -
#pragma mark - 同步异步方法的实现
/*
 1.参数节点
     doJsonNode *_dictParas = [parms objectAtIndex:0];
     a.在节点中，获取对应的参数
     NSString *title = [_dictParas GetOneText:@"title" :@"" ];
     说明：第一个参数为对象名，第二为默认值
 
 2.脚本运行时的引擎
     id<doIScriptEngine> _scritEngine = [parms objectAtIndex:1];
 
 同步：
 3.同步回调对象(有回调需要添加如下代码)
     doInvokeResult *_invokeResult = [parms objectAtIndex:2];
     回调信息
     如：（回调一个字符串信息）
     [_invokeResult SetResultText:((doUIModule *)_model).UniqueKey];
 异步：
 3.获取回调函数名(异步方法都有回调)
     NSString *_callbackName = [parms objectAtIndex:2];
     在合适的地方进行下面的代码，完成回调
     新建一个回调对象
     doInvokeResult *_invokeResult = [[doInvokeResult alloc] init];
     填入对应的信息
     如：（回调一个字符串）
     [_invokeResult SetResultText: @"异步方法完成"];
     [_scritEngine Callback:_callbackName :_invokeResult];
 */

//同步
- (void)beep:(NSArray *)parms
{
    //自己的代码实现
    AudioServicesPlaySystemSound (1106);
}
- (void)flash:(NSArray *)parms
{
    doJsonNode *_dictParams = [parms objectAtIndex:0];
    NSString *_status = [_dictParams GetOneText:@"status" :@""];
    if([_status isEqualToString:@"on"])
    {
        if(device == nil)
        {
            device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
        }
        if(!isLigthOn)
        {
            [device lockForConfiguration:nil];
            [device setTorchMode:AVCaptureTorchModeOn];
            [device unlockForConfiguration];
            isLigthOn = YES;
        }
    }
    
    else if([_status isEqualToString:@"off"])
    {
        if(device != nil)
        {
            [device lockForConfiguration:nil];
            [device setTorchMode: AVCaptureTorchModeOff];
            [device unlockForConfiguration];
            isLigthOn = NO;
        }
    }
}
- (void)getInfo:(NSArray *)parms
{
    doJsonNode *_dictParas = [parms objectAtIndex:0];
    
    doInvokeResult *_invokeResult = [parms objectAtIndex:2];
    //自己的代码实现
    NSString *str = [_dictParas GetOneText:@"name" :@""];
    
    NSArray *array = [[NSArray alloc]initWithObjects:@"deviceId",@"deviceName",@"OS",@"OSVersion",@"dpiH",@"dpiV",@"screenH",@"screenV",@"resolutionH",@"resolutionV",@"phoneType",@"communicationType",@"sdkVersion",nil];
    //实例化一个node，用以返回
    doJsonNode *node = [[doJsonNode alloc]init];
    doJsonNode *node2 = [[doJsonNode alloc]init];
    //获取设备id
    NSString *deviceId =  [[UIDevice currentDevice].identifierForVendor UUIDString];
    //获取设备名称
    NSString *deviceName = [UIDevice currentDevice].name;
    //获取设备操作系统
    NSString *OS = [UIDevice currentDevice].systemName;
    //获取设备操作系统版本号
    NSString *OSVersion = [UIDevice currentDevice].systemVersion;
    
    //获取设备水平像素密度
    NSString *dpiH = [NSString stringWithFormat:@"%d", (int )[[UIScreen mainScreen] scale]];
    //获取设备垂直像素密度
    NSString *dpiV = [NSString stringWithFormat:@"%d", (int )[[UIScreen mainScreen] scale]];
    //获取设备水平屏幕宽度
    NSString *screenH =[NSString stringWithFormat:@"%d",(int )[UIScreen mainScreen].bounds.size.width];
    //获取设备垂直屏幕宽度
    NSString *screenV =[NSString stringWithFormat:@"%d",(int )[UIScreen mainScreen].bounds.size.height];
    //获取设备水平分辨率
    NSString *resolutionH = [NSString stringWithFormat:@"%d",(int)[[UIScreen mainScreen] scale] * (int)[UIScreen mainScreen].bounds.size.width];
    
    //获取设备垂直分辨率
    NSString *resolutionV = [NSString stringWithFormat:@"%d",(int)[[UIScreen mainScreen] scale] * (int)[UIScreen mainScreen].bounds.size.height];
    //获取设备手机机型
    NSString *phoneType = [UIDevice currentDevice].model;
    
    //获取设备运营商类型
    CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
    CTCarrier *carrier = [info subscriberCellularProvider];
    NSString *communicationType = [NSString stringWithFormat:@"%@",[carrier carrierName]];
    //获取内存情况
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSFileManager *fileManager =[[NSFileManager alloc]init];
    NSDictionary *fileSysAttributes = [fileManager attributesOfFileSystemForPath:path error:nil];
    NSString *freeSpace = [fileSysAttributes objectForKey:NSFileSystemFreeSize];
    NSString *totalSpace = [fileSysAttributes objectForKey:NSFileSystemSize];
    NSString *sdkVersion = [NSString stringWithFormat:@"剩余%0.1fG/总共%0.1fG",[freeSpace longLongValue]/1024.0/1024.0/1024.0,[totalSpace longLongValue]/1024.0/1024.0/1024.0];
    
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]initWithObjectsAndKeys:deviceId,@"deviceId", deviceName,@"deviceName",OS,@"OS",OSVersion,@"OSVersion",dpiH,@"dpiH",dpiV,@"dpiV",screenH,@"screenH",screenV,@"screenH",resolutionH,@"resolutionH",resolutionV,@"resolutionH",phoneType,@"phoneType",communicationType,@"communicationType",sdkVersion,@"sdkVersion",nil];
    
    if([str isEqualToString:@""] || [[str lowercaseString] isEqualToString:@"all"])
    {
        for(int i = 0;i<[array count];i++)
        {
            [node SetOneText:[array objectAtIndex:i] :[dict objectForKey:[array objectAtIndex:i]]];
        }
        [_invokeResult SetResultNode:node];
    }
    else if([dict objectForKey:str])
    {
        [node2 SetOneText:str :[dict objectForKey:str]];
        [_invokeResult SetResultNode:node2];
    }
}
- (void)vibrate:(NSArray *)parms
{
    //震动，调用系统震动，每次调用都会实现1-2秒的震动
    AudioServicesPlaySystemSound (kSystemSoundID_Vibrate);
}

@end