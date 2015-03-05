//
//  doServiceContainer.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol doIGlobal;
@protocol doIScriptEngineFactory;
@protocol doILogEngine;
@protocol doII18NEngine;
@protocol doISingletonModuleFactory;
@protocol doIUIModuleFactory;
@protocol doIPageViewFactory;
@protocol doIPageFactory;
@protocol doIMultitonModuleFactory;
@protocol doIModuleExtManage;

@interface doServiceContainer : NSObject

#pragma mark -
@property (nonatomic,strong) id<doIGlobal> Global;
@property (nonatomic,strong) id<doIScriptEngineFactory> ScriptEngineFactory;
@property (nonatomic,strong) id<doILogEngine> LogEngine;
@property (nonatomic,strong) id<doII18NEngine> I18NEngine;
@property (nonatomic,strong) id<doISingletonModuleFactory> SingletonModuleFactory;
@property (nonatomic,strong) id<doIUIModuleFactory> UIModuleFactory;
@property (nonatomic,strong) id<doIMultitonModuleFactory> MultitonModuleFactory;
@property (nonatomic,strong) id<doIPageViewFactory> PageViewFactory;
@property (nonatomic,strong) id<doIPageFactory> PageFactory;
@property (nonatomic,strong) id<doIModuleExtManage> ModuleExtManage;


#pragma mark -
+ (doServiceContainer *) Instance;
@end
