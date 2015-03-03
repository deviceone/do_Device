//
//  doDataDict.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doJsonValue.h"
#import "doIConvert.h"

@interface doDict : NSObject
{
    @private
     NSMutableDictionary* dictValues;
}
#pragma mark -
-(NSString*) GetData:(NSString*) _key;
-(void) SetData:(NSString*) _key : (NSString*) _value;
-(NSMutableDictionary*) GetAllValues;
-(void) Dispose;
-(doJsonNode*) ExportToJson;
-(NSString*) ExportToText;
#pragma mark -
+(doDict*) LoadFromJsonData:(doJsonValue*) _rootJsonValue : (NSString*) _path :(id<doIConvert>) _convert;
@end
