//
//  doProperty.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import <Foundation/Foundation.h>
@class doModule;
@class doJsonValue;

typedef enum
{
    String,
    Bool,
    Number
} PropertyDataType;

@interface doProperty : NSObject

#pragma mark -
- (id) init: (NSString*) _propertyID : (PropertyDataType)_propertyDataType :(NSString *)_defaultValue :(BOOL)_designOnly;

#pragma mark -
@property(weak,nonatomic)doModule* CurrentComponet;
@property(strong,nonatomic,readonly)NSString* ID;
@property(strong,nonatomic)NSString* DefaultValue;
@property(assign,nonatomic)BOOL DesignOnly;
@property(assign,nonatomic)PropertyDataType DataType;
@property(strong,nonatomic)NSString* Value;
@property(strong,nonatomic)NSString* BindModel;
@property(strong,nonatomic)NSString* BindPath;

#pragma mark -
- (void) SetJsonNodeValue: (doJsonValue *) _jsonValue;

@end
