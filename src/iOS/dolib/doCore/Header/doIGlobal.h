//
//  doIGlobal.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIApp;

@protocol doIGlobal <NSObject>

#pragma mark -
@property (nonatomic, strong) NSString * SourceRootPath;
@property (nonatomic, strong) NSString * DataRootPath;
@property (nonatomic, assign) double ScreenWidth;
@property (nonatomic, assign) double ScreenHeight;
@property (nonatomic, readonly, strong) NSString * OSType;//操作系统类型
@property (nonatomic, readonly, strong) NSString * OSVersion;//操作系统版本
@property (nonatomic, readonly, strong) NSString * MainAppID;//主应用ID
@property (nonatomic, readonly, strong) NSString * ScriptType;
@property (strong, nonatomic) NSString* LaunchType;//启动方式。
@property (strong, nonatomic) NSString* LaunchData;//被其他启动时带的数据

#pragma mark -
@required
- (id<doIApp>) GetAppByID: (NSString *) _appID;
- (id<doIApp>) GetAppByAddress: (NSString *) _key;
- (void) LoadConfig: (NSString*) _configFileName;
- (void) ClearAllApps;
@end