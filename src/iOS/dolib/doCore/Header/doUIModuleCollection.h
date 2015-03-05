//
//  doUIModuleContainer.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import "doUIModule.h"

@interface doUIModuleCollection : doUIModule

@property(strong,nonatomic,readonly) NSMutableArray* ChildUIModules;
@property(assign,nonatomic)double InnerXZoom;
@property(assign,nonatomic)double InnerYZoom;
@end
