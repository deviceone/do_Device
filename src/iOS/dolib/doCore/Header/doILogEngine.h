//
//  doILogEngine.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doILogEngine 

#pragma mark -
@required
//日志管理引擎
- (void) WriteError: (NSException *) _err : (NSString *) _desc ,... ;
- (void) WritePerformance: (NSString *) _opt : (int) _time;
- (void) WriteDebug: (NSString *) _content;

@end