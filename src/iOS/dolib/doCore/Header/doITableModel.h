//
//  doITableModel.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doTable.h"

@protocol doGetDataTableCallBack
#pragma mark -
//delegate
@required
-(void) doGetDataTableCallBack: (doTable*) _dataTable;
@end

@protocol doITableModel
#pragma mark -
@required
-(void) DefineTableBind:(NSString*) _uniqueKey : (id<doGetDataTableCallBack>) _callback;
@end
