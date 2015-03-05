//
//  doIVirtualTableModel.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doIDictionaryModel.h"
@protocol doRefreshFirstPageCallBack
#pragma mark -
//delegate
@required
-(void) doRefreshFirstPageCallBack:(BOOL) _changed;
@end

@protocol doIVirtualTableModel <NSObject>
#pragma mark -
@required
-(BOOL) GetDict:(int) _row : (id<doGetDataDictCallBack>) _callback;
-(void) RefreshFirstPage :(id<doRefreshFirstPageCallBack>) _callback;
@end
