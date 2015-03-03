//
//  doIDataFS.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "doIApp.h"
@protocol doIApp;

@protocol doIDataFS //FS是File System的缩写  文件系统

#pragma mark -
@property (nonatomic, readonly, weak) id<doIApp> CurrentApp;
@property (nonatomic, readonly, strong) NSString * RootPath;
//应用数据目录-系统
@property (nonatomic, readonly, strong) NSString * PathSys;
//应用数据目录-系统-缓存
@property (nonatomic, readonly, strong) NSString * PathSysCache;
//应用数据目录-公共
@property (nonatomic, readonly, strong) NSString * PathPublic;
//应用数据目录-私有
@property (nonatomic, readonly, strong) NSString * PathPrivate;
//应用数据目录-私有临时
@property (nonatomic, readonly, strong) NSString * PathPrivateTemp;
//应用数据目录-安全
@property (nonatomic, readonly, strong) NSString * PathSecurity;

#pragma mark -
@required
//获取完整的路径
- (NSString *)GetFileFullPathByName: (NSString *) _fileName;

//释放资源
- (void)Dispose;

@end