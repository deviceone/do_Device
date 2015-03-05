//
//  doEventCenter.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doInvokeResult.h"

@protocol doIScriptEngine;
@interface doEventCenter : NSObject
{
    @private
    NSMutableDictionary* dictEventCollection;
}
#pragma mark -
- (void) Dispose;
- (void) Subscribe: (NSString*) _messageName : (NSString*) _callbackName : (id<doIScriptEngine>) _scriptEngine;
- (void) Unsubscribe: (NSString*) _messageName : (id<doIScriptEngine>) _scriptEngine;
- (void) FireEvent: (NSString*) _messageName : (doInvokeResult*) _invokeResult;
- (void) SetResponseTime: (NSString*) _messageName : (NSTimeInterval) _responseTime;
- (void) SetEventData: (NSString*) _messageName : (NSString*) _eventData;
@end
