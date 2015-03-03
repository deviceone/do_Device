//
//  doScriptEngineHelper.h
//  DoCore
//
//  Created by 刘吟 on 14/12/4.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doUIModule.h"
#import "doIScriptEngine.h"
#import "doSingletonModule.h"
#import "doMultitonModule.h"

@interface doScriptEngineHelper : NSObject
//根据路径，找到相关组件
/*
 .为分隔符，
 $：所属视图，
 @：当前页面下，指定地址的对象,
 其它默认：当前视图的下，指定ID的对象
 注:所有路径都是基于当前页面的，禁止跨页面访问组件对象；
 */
+(doUIModule*) ParseUIModule:(id<doIScriptEngine>) _scriptEngine : (NSString*) _path;
//根据路径，找到相关API类
/*
 ^[AppID]：指定ID的App，
 @：指定地址的API对象,
 其它默认：指定ID的API对象
 注: 不支持.分割的路径
 */
+(doSingletonModule*) ParseSingletonModule:(id<doIScriptEngine>) _scriptEngine : (NSString*) _path;
//根据路径，找到相关Model类
/*
 @：指定地址的Model对象,
 注: 不支持.分割的路径
 */
+(doMultitonModule*) ParseMultitonModule:(id<doIScriptEngine>) _scriptEngine : (NSString*) _path ;
+(BOOL) InvokeSyncSelector:(id) _self : (NSString*) _methodName : (doJsonNode *) _dictParas :(id<doIScriptEngine>) _scriptEngine : (doInvokeResult *)_invokeResult;
+(BOOL) InvokeASyncSelector:(id) _self :(NSString *) _methodName : (doJsonNode *) _dictParas :(id<doIScriptEngine>) _scriptEngine : (NSString *) _callbackFuncName ;

@end
