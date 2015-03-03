//
//  doIScriptEngine.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
//脚本运行时的引擎
@protocol doIApp;
@protocol doIPage;
@class doInvokeResult;
@class doCallBackTask;

@protocol doIScriptEngine

#pragma mark -
//当前应用
@property (nonatomic,weak) id<doIApp> CurrentApp;
//当前页面
@property (nonatomic,weak) id<doIPage> CurrentPage;

#pragma mark -
@required
//初始化
- (void) Init;
//释放资源
- (void) Dispose;
//函数回调
- (void) Callback:(NSString *)_methodName :(doInvokeResult *)_invokeResult;
//运行脚本
- (void) LoadScripts:(NSString *)_scripts;
//创建回调任务
- (doCallBackTask *) CreateCallBackTask:(NSString *)_callBackMethodName;

-(void) CallLoadScriptsAsModel:(NSString *)_scripts : (NSString*) libname;
-(void) CallLoadScriptsAsModelWithPreDefine:(NSString*) uiRootViewAddress :(NSString *)_scripts;
@end
