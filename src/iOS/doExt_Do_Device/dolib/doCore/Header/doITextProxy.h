//
//  doITextProxy.h
//  DoCore
//
//  Created by 刘吟 on 14/12/4.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol doGetTextCallBack
#pragma mark -
//delegate
@required
-(void) doGetTextCallBack: (NSString*) _respondData;
@end

@protocol doITextProxy 
#pragma mark -
@required
-(void) RebindSource:(NSMutableDictionary*) _dictBind;
-(void) GetTextData:(id<doGetTextCallBack>) _callback;
@end
