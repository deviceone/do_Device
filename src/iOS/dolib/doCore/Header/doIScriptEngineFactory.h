//
//  doIScriptEngineFactory.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIScriptEngineGroup;
@protocol doIScriptEngine;
@protocol doIApp;
@protocol doIPage;


@protocol doIScriptEngineFactory 

#pragma mark -
@required
- (void)RegisterGroup: (id<doIScriptEngineGroup>) _scriptContainer;
- (id<doIScriptEngine>) CreateScriptEngine: (id<doIApp>) _app :(id<doIPage>) _page;

- (void) SetDeviceOneLibScriptPath:(NSString*) _scriptPath;
@end