//
//  doIMultitonModuleFactory.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doMultitonModule.h"
@protocol doIMultitonModuleGroup;

@protocol doIMultitonModuleFactory 
#pragma mark -
@required
-(doMultitonModule*) CreateMultitonModule:(NSString*) _typeID;
-(void) RegistGroup: (id<doIMultitonModuleGroup>) _moduleGroup;
@end
