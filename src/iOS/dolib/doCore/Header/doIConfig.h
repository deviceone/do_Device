//
//  doIConfig.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIApp;

@protocol doIConfig

#pragma mark -
@property (nonatomic, readonly, weak) id<doIApp> CurrentApp;
@property (nonatomic, readonly, strong) NSString * StartScriptName;
@property (nonatomic, readonly, strong) NSString * StartScriptType;
@property (nonatomic, readonly, strong) NSString * DesignScriptType;
@property (nonatomic, readonly, assign) double DesignScreenWidth;
@property (nonatomic, readonly, assign) double DesignScreenHeight;

#pragma mark -
//释放资源
@required
- (void) Dispose;
- (BOOL) IsMatched;

@end
