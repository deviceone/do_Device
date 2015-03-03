//
//  doIOHelper.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doSourceFile.h"
#import "doIApp.h"

@interface doIOHelper : NSObject
#pragma mark -
+(NSString*) GetLocalFileFullPath:(id<doIApp>) _app :(NSString*) _targetFilePath;
//GetHttpUrlPath获取url的全路径
+(NSString*) GetLocalFileFullPath2:(doSourceFile*) _sourceFile : (NSString*) _targetFilePath;
//GetHttpUrlPath获取url的全路径
+ (NSString*) GetHttpUrlPath :(NSString*) _targetFilePath;
+ (NSString*) GetUTF8String:(NSData*) _src;
+ (NSString*) ReadUTF8File:(NSString*) _fileName;
+ (BOOL) ExistDirectory : (NSString*)  _dirFullName;
+ (void) CreateDirectory :(NSString*) _directory;
+ (void) WriteAllBytes :(NSString*)_fileFullName :(NSData*) _content;
@end
