//
//  doCallBackTask.h
//  DoCore
//
//  Created by 刘吟 on 14/11/16.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@class doInvokeResult;
@protocol doIScriptEngine;
@class doEventCollection;

@interface doCallBackTask : NSObject
{
    @private
    NSString* callbackMethodName;
}
#pragma mark -
- (id) init: (id<doIScriptEngine>) _scriptEngine : (NSString*) _callbackMethodName;

#pragma mark -
@property(readonly,weak,nonatomic)id<doIScriptEngine> ScriptEngine;

#pragma mark -
- (void) Dispose;
- (void) Callback: (doInvokeResult*) _invokeResult;

@end