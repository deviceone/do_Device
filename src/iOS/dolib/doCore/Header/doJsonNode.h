//
//  doJsonNode.h
//  DoCore
//
//  Created by zhangwd on 14-11-12.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doJsonValue.h"

@interface doJsonNode : NSObject

@property (strong,nonatomic) NSMutableDictionary *dictValues;
@property (strong,nonatomic) NSMutableArray *listValues;
@property (assign,nonatomic) BOOL CaseSensitive;

// 加载数据流
- (void)LoadDataFromStream:(id)_reader;

// 获得所有的Value
- (NSMutableArray *)GetAllValues;
- (NSMutableDictionary *) GetAllKeyValues;

// 获得一个Value
- (doJsonValue*)GetOneValue:(NSString*)_name;

// 设置一个Value
- (void)SetOneValue:(NSString*)_name :(doJsonValue*)_value;

// 设置一个整数
- (int)GetOneInteger:(NSString*)_name :(int)_defaultValue;

// 设置一个Float
- (double)GetOneFloat:(NSString*)_name :(double)_defaultValue;

// 获得一个文本
- (NSString*)GetOneText:(NSString*)_name :(NSString*)_defaultValue;

// 获得一个BOOL
- (BOOL)GetOneBoolean:(NSString*)_name :(BOOL)_defaultValue;

// 获得一个节点
- (doJsonNode*)GetOneNode:(NSString*)_name;

// 获得一个数组
- (NSArray*)GetOneArray:(NSString*)_name;

// 获得一个节点数组
- (NSArray*)GetOneNodeArray:(NSString*)_name;

// 获得一个文本数组
- (NSArray*)GetOneTextArray:(NSString*)_name;

// 设置一个Integer
- (void)SetOneInteger:(NSString*)_name :(int)_value;

// 设置一个Float
-(void)SetOneFloat:(NSString*)_name :(double)_value;

// 设置一个文本
-(void)SetOneText:(NSString*)_name :(NSString*)_value;

// 设置一个bool
-(void)SetOneBoolean:(NSString*)_name :(BOOL)_value;

// 设置一个节点
-(void)SetOneNode:(NSString*)_name :(doJsonNode *)_value;

// 设置一个数组
-(void)SetOneArray:(NSString*)_name :(NSArray*)_array;

// 设置一个节点数组
-(void)SetOneNodeArray:(NSString*)_name :(NSArray*)_values;

// 设置一个文本数组
-(void)SetOneTextArray:(NSString*)_name :(NSArray*)_values;

// 导出流
-(void)ExportToStream:(id)_jsonWriter;

// 导出到文本
-(NSString*)ExportToText;

@end
