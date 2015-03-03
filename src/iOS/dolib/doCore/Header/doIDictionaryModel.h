//
//  doIDictionaryModel.h
//  DoCore
//
//  Created by 刘吟 on 14/12/3.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "doDict.h"

@protocol doGetDataDictCallBack
#pragma mark -
//delegate
@required
-(void) doGetDataDictCallBack: (doDict*) _dataDict;
@end

@protocol doIDictionaryModel
#pragma mark -
@required
-(void) DefineDictBind:(NSString*) _uniqueKey : (id<doGetDataDictCallBack>) _callback;
@end
