//
//  doIScriptEngineGroup.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

//脚本运行时引擎的容器
@protocol doIScriptEngine;

@protocol doIScriptEngineGroup

#pragma mark -
- (id<doIScriptEngine>) CreateScriptEngine: (NSString *)_scriptType;

@end