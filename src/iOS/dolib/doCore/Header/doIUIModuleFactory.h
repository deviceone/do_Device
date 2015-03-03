//
//  doIUIModuleFactory.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@class doUIModule;
@protocol doIUIModuleGroup;
@protocol doIUIModuleView;
@protocol doIPage;


@protocol doIUIModuleFactory

#pragma mark -
@required
- (doUIModule *) CreateUIModule: (NSString *)_typeID;
- (void)BindUIModuleView:(doUIModule *) _module;
- (void) RegistGroup: (id<doIUIModuleGroup>) _uiModuleGroup;

@end
