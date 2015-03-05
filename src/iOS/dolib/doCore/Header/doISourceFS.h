//
//  doISourceFS.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIApp;
@class doSourceFile;

@protocol doISourceFS

#pragma mark -
@property (nonatomic, readonly, weak) id<doIApp> CurrentApp;
@property (nonatomic, readonly, strong) NSString * RootPath;

#pragma mark -
@required
- (doSourceFile *) GetSourceByFileName: (NSString *)_fileName;
- (doSourceFile *) GetSourceByFileFullName: (NSString *)_fileFullName;
- (NSString *) GetFileFullPathByName: (NSString *)_fileName;
//释放资源
- (void) Dispose;

@end
