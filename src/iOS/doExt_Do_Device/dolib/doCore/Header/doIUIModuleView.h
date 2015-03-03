//
//  doIUIModuleView.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@class doUIModule;
@class doJsonNode;
@protocol doIScriptEngine;
@class doInvokeResult;
//组件的视图
@protocol doIUIModuleView 

#pragma mark -
@required
- (void) LoadView: (doUIModule *) _doUIModule;
- (doUIModule *) GetModel;
- (void) OnDispose;
- (BOOL) OnPropertiesChanging: (NSMutableDictionary *) _changedValues;
- (void) OnPropertiesChanged: (NSMutableDictionary*) _changedValues;
- (BOOL) InvokeSyncMethod: (NSString *) _methodName : (doJsonNode *)_dicParas :(id<doIScriptEngine>)_scriptEngine : (doInvokeResult *) _invokeResult;
- (BOOL) InvokeAsyncMethod: (NSString *) _methodName : (doJsonNode *) _dicParas :(id<doIScriptEngine>) _scriptEngine : (NSString *) _callbackFuncName;
- (void) OnRedraw;
@end
