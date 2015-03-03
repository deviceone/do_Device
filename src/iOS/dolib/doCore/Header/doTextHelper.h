//
//  doTextHelper.h
//  libDolib
//
//  Created by sqs on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface doTextHelper : NSObject

+ (doTextHelper*) Instance;

// 使用 base64  进行编码
- (NSString*) Base64Encode:(NSData*)_src;
- (NSString*) Base64Encode:(NSData*)_src :(int)_start :(int)_length;
- (NSData*) Base64Decode:(NSString*)_src :(NSMutableData*)_defaultVal;
// 使用 MD5  进行编码
- (NSString *) MD5:(NSString *)_src;
//将字符串转换成整数
-(int) StrToInt:(NSString *)str :(int)defaultVal;

//将字符串转换成长整数
-(long long) StrToLong:(NSString*)str :(int) defaultVal;

//将字符串换换成double类型
- (double) StrToDouble:(NSString*)str :(int) defaultVal;
-(BOOL) StrToBool:(NSString*)str :(BOOL) defaultVal;
//将字符串转换成float
- (float) StrToFloat:(NSString*)str :(float) defaultVal;

//将二进制转换成16进制的字符串
- (NSString*) Bytes2HexString:(NSData*)_data;

//将16进制格式的字符串转换到二进制
- (NSData*) B16StrToBytes:(NSString*)_data;
+(NSString*) ComputeHashValue:(NSString*) _st;
@end
