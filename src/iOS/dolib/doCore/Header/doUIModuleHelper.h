//
//  doUIModuleHelper.h
//  DoCore
//
//  Created by zhangwd on 14-11-12.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIKit.h>

@class doUIModule;
@class doSourceFile;
@protocol doIPage;
@protocol doIApp;
@protocol doIScriptEngine;

@interface doUIModuleHelper : NSObject
+ (void)HandleViewProperChanged:(id) _self :(doUIModule *)_uiModule :(NSMutableDictionary*) _changedValues;
+ (void)HandleBasicViewProperChanged:(doUIModule *)_uiModule :(NSMutableDictionary*) _changedValues;
+ (void) OnRedraw:(doUIModule*) _uiModule;
+ (UIColor*) GetColorFromString: (NSString*) _colorStr : (UIColor*) _default;
+ (NSString*) GetTagContent:(UIView*) _view;
+ (BOOL) IsLandscape;

+(NSString*)GetCloseAnimation:(NSString*)animationIn;
+(CATransition*)GetAnmation:(NSString*)anmationType :(float)time
;
+(void)Alert:(NSString*)title msg:(NSString*)msg;
+(UIImage*)imageWithImageSimple:(UIImage*)image scaledToSize:(CGSize)newSize;
+ (CGSize)sizeWithImageData:(UIImage *)image;
+ (NSString *)stringWithUUID;
+(int)GetDeviceFontSize:(int) _fontSize : (float) xzoom : (float) yzoom;
@end
