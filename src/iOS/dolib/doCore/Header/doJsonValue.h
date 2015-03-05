//
//  doJsonValue.h
//  DoCore
//
//  Created by zhangwd on 14-11-12.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum
{
    doBoolean, //Boolean已经是ios关键字了，所以统一加do前缀
    doTextValue,
    doIntegerValue,
    doFloatValue,
    doNodeValue,
    doArrayValue
} doConfigValueType;

@class doJsonNode;

@interface doJsonValue : NSObject
{
    BOOL BooleanValue;
    NSString *TextValue;
    int IntegerValue;
    double FloatValue;
    doJsonNode *NodeValue;
    NSMutableArray *ArrayValue;
}

@property (readonly,nonatomic) doConfigValueType ValueType;
@property (strong,nonatomic) NSMutableDictionary *allDic;
@property (strong,nonatomic) NSString *NodeName;

- (void)LoadDataFromText:(NSString*)_text;
- (void)LoadDataFromeStream:(id)_reader :(BOOL)_firstFinished;
- (void)SetBoolean:(BOOL)_value;
- (void)SetText:(NSString*)_value;
- (void)SetInteger:(int)_value;
- (void)SetFloat:(double)_value;
- (void)SetNode:(doJsonNode*)_value;
- (void)SetArray:(NSArray*)_values;
- (void)SetNodeArray:(NSArray*)_values;
- (void)SetTextArray:(NSArray*)_values;
- (NSString*)ExportToText:(BOOL)_indented;
- (NSString*)GetText:(NSString*)_defaultValue;
- (BOOL)GetBoolean:(BOOL)_defaultValue;
- (int)GetInteger:(int)_defaultValue;
- (double)GetFloat:(int)_defaultValue;
- (doJsonNode*)GetNode;
- (NSArray*)GetArray;
- (void)ExportToStream:(id)_jsonWriter :(NSString*)key;
@end
