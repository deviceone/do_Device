//
//  doMultitonModule.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol doIApp;
#import "doModule.h"
#import "doIScriptEngine.h"
#import "doJsonValue.h"
#import "doJsonNode.h"
#import "doProperty.h"

@interface doMultitonModule : doModule
{
    @private
    NSString* configData;
    @protected
    NSMutableDictionary* dictProperties;//处理成员属性
}
#pragma mark -
//当前所属应用
@property (nonatomic,weak) id<doIApp> CurrentApp;
//当前所属页面
@property (nonatomic,weak) id<doIPage> CurrentPage;
//protected
- (void) RegistProperty: (doProperty*) _property;
- (void) SetPropertyValue: (NSString*) _key : (NSString*) _val;//设置属性值
- (NSString*) GetPropertyValue: (NSString*) _key;//获取属性值
#pragma mark -
//绑定配置 abstract
- (void) InitModel: (id<doIScriptEngine>) _scriptEngine : (doInvokeResult*) _invokeResult : (doJsonValue*) _rootJsonValue;
@end
