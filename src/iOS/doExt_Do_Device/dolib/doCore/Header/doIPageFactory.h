//
//  doIPageFactory.h
//  DoCore
//
//  Created by 刘吟 on 14/11/16.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol doIPage;
@protocol doIPageView;
@class doSourceFile;
@protocol doIApp;

@protocol doIPageFactory

#pragma mark -
@required
- (id<doIPage>) CreatePage :(id<doIApp>) _doApp : (id<doIPageView>) _pageView : (doSourceFile *) _uiFile ;

@end
