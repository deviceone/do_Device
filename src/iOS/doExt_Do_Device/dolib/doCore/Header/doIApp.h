//
//  doIApp.h
//  libDolib
//
//  Created by sqs on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doMultitonModule.h"
@protocol doIDataFS;
@protocol doISourceFS;
@protocol doIConfig;
@protocol doIScriptEngine;

@protocol doIApp <NSObject>
#pragma mark -
@property (nonatomic, readonly, strong)NSString * AppID;
@property (nonatomic, readonly, strong)id<doIDataFS> DataFS;
@property (nonatomic, readonly, strong)id<doISourceFS> SourceFS;
@property (nonatomic, readonly, strong)id<doIConfig> Config;
@property (nonatomic,readonly,strong) id<doIScriptEngine> ScriptEngine;

#pragma mark -
@required
- (id<doIConfig>) GetConfig:(NSString *) _adapterID;
-(doMultitonModule*) CreateMultitonModule:(NSString*) _typeID;
-(doMultitonModule*) GetMultitonModuleByAddress:(NSString*) _key;
-(BOOL) DeleteMultitonModule:(NSString*) _address;
-(void) Dispose;
@end
