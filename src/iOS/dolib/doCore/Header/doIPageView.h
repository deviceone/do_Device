//
//  doIPageView.h
//  libDolib
//
//  Created by 程序员 on 14/11/11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol doIPage;

@protocol doIPageView

#pragma mark -
@property (nonatomic, readonly,strong) id<doIPage> PageModel;
#pragma mark -
@required
- (void) DisposeView;

@end
