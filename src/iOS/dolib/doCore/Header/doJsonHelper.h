//
//  doJsonHelper.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doJsonValue.h"

@interface doJsonHelper : NSObject
+(doJsonValue*) getJsonValue:(doJsonValue*) _rootValue : (NSString*) _dataPath;
@end
