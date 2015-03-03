//
//  doIUIModuleGroup.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@class doUIModule;
@protocol doIUIModuleView;
@protocol doIPage;

@protocol doIUIModuleGroup

//UI组件的工厂管理
#pragma mark -
@required
- (doUIModule *) CreateUIModule: (NSString *)_typeID;
- (id<doIUIModuleView>) CreateUIModuleView : (doUIModule *)_module;

@end

