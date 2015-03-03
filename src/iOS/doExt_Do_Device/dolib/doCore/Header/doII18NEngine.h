//
//  doII18NEngine.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

//国际化引擎管理
@protocol doII18NEngine 
#pragma mark -
@required
//key的格式是package.id, 比如com.deviceone.doxxx.yy
- (NSString *)GetText:(NSString *)key;

@end
