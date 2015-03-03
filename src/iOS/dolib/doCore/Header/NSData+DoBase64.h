//
//  NSData+DoBase64.h
//  libDolib
//
//  Created by zhangwd on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (DoBase64)

+ (id)dataWithBase64EncodedString:(NSString *)string;

- (NSString *)base64Encoding;
@end
