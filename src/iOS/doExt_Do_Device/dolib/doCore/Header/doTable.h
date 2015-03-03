//
//  doDataTable.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doDict.h"

@interface doTable : NSObject
{
@private
    NSMutableArray* listDataRows;
}
#pragma mark -
-(doDict*) GetData:(int) _rownum;
-(NSUInteger) GetRowCount;
-(void) AppendData: (doDict*) _dataDict;
-(void) Dispose;
-(NSString*) ExportToText;
#pragma mark -
+(doTable*) LoadFromJsonData:(doJsonValue*) _rootJsonValue : (NSString*) _path :(id<doIConvert>) _convert;

@end
