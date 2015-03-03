//
//  doSingletonModuleHelper.h
//  DoCore
//
//  Created by zhangwd on 14-11-12.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@class doSingletonModule;
@protocol  doIScriptEngine;
@interface doSingletonModuleHelper : NSObject
+ (NSData*) HttpDownloadData:(NSString*) _url;
@end
