//
//  doStack.h
//  DoCore
//
//  Created by 刘吟 on 14/12/9.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface doStack : NSObject
{
    @private
    NSMutableArray* m_array;
    NSUInteger _count;
}
- (void)push:(id)anObject;
- (id)pop;
- (void)clear;
@property (nonatomic, readonly,assign) NSUInteger count;

@end
