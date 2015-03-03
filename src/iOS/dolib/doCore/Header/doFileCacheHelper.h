//
//  doFileCacheHelper.h
//  DoCore
//
//  Created by 刘吟 on 14/12/4.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doIApp.h"
@protocol GetFileResult
#pragma mark -
//delegate
@required
-(void) GetFileResult: (NSString*) _cachedFile;
@end

@interface doFileCacheHelper : NSObject
+(NSString*) GetCachedFileFullName:(id<doIApp>) _app :(NSString*) _cacheID;
@end
