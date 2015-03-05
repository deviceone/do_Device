//
//  doIPage.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doUIModule.h"
#import "doIApp.h"
#import "doSourceFile.h"
#import "doIScriptEngine.h"
#import "doJsonNode.h"
#import "doIPageView.h"

@protocol doIApp;
@class doSourceFile;
@protocol doIScriptEngine;
@class doUIContainer;
@class doJsonNode;
@protocol doIPageView;

@protocol doIPage

#pragma mark -
@property (nonatomic, readonly, weak) id<doIApp> CurrentApp;
@property (nonatomic, readonly, strong) id<doIPageView> PageView;
@property (nonatomic, readonly, strong) doSourceFile * UIFile;
@property (nonatomic, readonly, strong) id<doIScriptEngine> ScriptEngine;
@property (nonatomic, readonly, strong) doUIModule* RootView;
@property (nonatomic, strong) NSString * Data;
@property (nonatomic, assign) BOOL IsFullScreen;
@property (nonatomic, strong) NSString * SoftMode;

#pragma mark -
@required
- (doUIModule *) CreateUIModule: (doUIContainer *)_uiContainer : (doJsonNode *) _moduleNode;
- (void) RemoveUIModule: (doUIModule *)_module;

- (doUIModule *) GetUIModuleByAddress: (NSString *) _key;
- (void) LoadRootUiContainer;
- (void) LoadScriptEngine: (NSString *) _scriptFile;
-(doMultitonModule*) CreateMultitonModule:(NSString*) _typeID;
-(doMultitonModule*) GetMultitonModuleByAddress:(NSString*) _key;
-(BOOL) DeleteMultitonModule:(NSString*) _address;
- (void) Dispose;
@end