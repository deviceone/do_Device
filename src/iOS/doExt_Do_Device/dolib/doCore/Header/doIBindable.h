//
//  doIBindable.h
//  DoCore
//
//  Created by 刘吟 on 14/12/4.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIBindable
#pragma mark -
@required
-(void) UnBind:(NSString*) _uniqueKey;
@end
