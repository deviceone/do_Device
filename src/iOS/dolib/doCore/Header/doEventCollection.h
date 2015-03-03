//
//  doEventCollection.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@class doCallBackTask;
@protocol doIScriptEngine;
@class doInvokeResult;

@interface doEventCollection : NSObject
{
    @private
    NSMutableArray* callBackCollection;
    NSDate* lastResponseTime;
}
#pragma mark -
@property(strong,nonatomic)NSString* MessageID;
@property(strong,nonatomic)NSString* EventData;//透传数据
@property(assign,nonatomic)NSTimeInterval ResponseTimeLimit;

#pragma mark -
- (void) Dispose;
- (void) Subscribe: (doCallBackTask*) _callbackTask;
- (void) Unsubscribe: (id<doIScriptEngine>) _scriptEngine;
- (void) ReSubscibeMessage: (doCallBackTask*) _callbackTask;
- (void) FireEvent: (doInvokeResult*) _jsonResult;
@end
