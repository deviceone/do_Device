//
//  doIAnimationModel.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@class doUIModule;
@protocol doIAnimation 
-(void) SetAnimation:(doUIModule *) _comp :(NSString*) _callbackName;
@end
