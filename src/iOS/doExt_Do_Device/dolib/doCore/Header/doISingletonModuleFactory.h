//
//  doISingletonModuleFactory.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

//API组件的工厂管理
@class doSingletonModule;
@protocol doIScriptEngine;
@protocol doISingletonModuleGroup;

@protocol  doISingletonModuleFactory

#pragma mark -
@required
- (doSingletonModule *) GetSingletonModuleByID: (id<doIScriptEngine>) _scriptEngine : (NSString *) _typeID;
- (doSingletonModule *) GetSingletonModuleByAddress:(NSString *)_key;
- (void)RegistGroup: (id<doISingletonModuleGroup>) _moduleGroup;
-(void) RemoveSingletonModuleByAddress:(NSString*) _address;

@end
