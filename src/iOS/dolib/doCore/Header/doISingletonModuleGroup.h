//
//  doISingletonModuleGroup.h
//  DoCore
//
//  Created by 刘吟 on 14/11/16.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol doIScriptEngine;
@class doSingletonModule;
@protocol doISingletonModuleGroup 

#pragma mark -
@required
- (doSingletonModule *)CreateSingletonModule:(id<doIScriptEngine>)  _scriptEngine :(NSString *)_typeID;

@end
