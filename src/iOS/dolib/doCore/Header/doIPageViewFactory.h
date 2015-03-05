//
//  doIPageViewFactory.h
//  DoCore
//
//  Created by 刘吟 on 14/11/16.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIPageViewFactory 

#pragma mark -
@required
- (void) OpenPage: (NSString*) _appID : (NSString*) _uiPath : (NSString*) _scriptType :  (NSString*) _animationType : (NSString*)_data : (NSString*)_isFullScreen  : (NSString*)_keyboardMode :(NSString*) _callbackName;
- (void) ClosePage:(NSString*) _animationType :(NSString*) _data;
@end
