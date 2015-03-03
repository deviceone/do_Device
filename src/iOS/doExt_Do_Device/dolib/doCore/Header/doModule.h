//
//  doModule.h
//  libDolib
//
//  Created by sqs on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doEventCenter.h"
@class doJsonNode;
@protocol doIScriptEngine;
@class doInvokeResult;

@interface doModule : NSObject
{
    @private
    NSString* uniqueKey;
}
#pragma mark -
@property(strong,nonatomic,readonly)doEventCenter * EventCenter;
@property(strong,nonatomic,readonly)NSString *UniqueKey;
@property(strong,nonatomic)NSString *TypeID;
#pragma mark -
#pragma mark - virtual
- (void) OnInit;
//virtual
- (void) Dispose;
//virtual
-(BOOL) InvokeSyncMethod: (NSString*) _methodName : (doJsonNode *) _dictParas :(id<doIScriptEngine>) _scriptEngine : (doInvokeResult *)_invokeResult;
//virtual
-(BOOL) InvokeAsyncMethod: (NSString *) _methodName : (doJsonNode *) _dictParas :(id<doIScriptEngine>) _scriptEngine : (NSString *) _callbackFuncName;

@end
