//
//  doUIModule.h
//  libDolib
//
//  Created by linliyuan on 14-11-11.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import "doModule.h"
#import "doIDictionaryModel.h"
#import "doITableModel.h"
@protocol doIPage;
@class doInvokeResult;
@protocol doIUIModuleView;
@class doProperty;
@class doUIModuleCollection;
@class doUIContainer;

@interface doMargins : NSObject
@property(assign,nonatomic)double l;//左
@property(assign,nonatomic)double t;//上
@property(assign,nonatomic)double r;//右
@property(assign,nonatomic)double b;//下
-(id) init:(NSString*) _mar;
@end

@interface doUIModule : doModule
{
    @private
    NSString* uiid;
    NSMutableDictionary* initilizedProperties;
    @protected
    NSMutableDictionary* dictProperties;//处理成员属性
}
#pragma mark -
@property(strong,nonatomic) doUIModuleCollection* ParentUICollection;//当前所属父控件
@property(weak,nonatomic)id<doIPage> CurrentPage;//当前所属页面
@property(strong,nonatomic)doUIContainer* CurrentUIContainer;//当前所属视图
@property(strong,nonatomic)id<doIUIModuleView> CurrentUIModuleView;//相关的组件
@property(strong,nonatomic)doUIContainer* UIContainer;//如果是一个RootView，这个值才有值，否则为nil
@property(strong,nonatomic,readonly)NSString* ID;//
@property(assign,nonatomic)double X;
@property(assign,nonatomic)double Y;
@property(assign,nonatomic)double Width;
@property(assign,nonatomic)double Height;
//控件转换到设备上的坐标和尺寸
@property(assign,nonatomic)double XZoom;
@property(assign,nonatomic)double YZoom;
@property(assign,nonatomic)double RealX;
@property(assign,nonatomic)double RealY;
@property(assign,nonatomic)double RealWidth;
@property(assign,nonatomic)double RealHeight;
@property(assign,nonatomic)NSString* Tag;
@property(assign,nonatomic)doMargins* Margins;

#pragma mark -
- (void) LoadView;
//protected
- (void) RegistProperty: (doProperty*) _property;
- (void) SetPropertyValue: (NSString*) _key : (NSString*) _val;//设置属性值
- (NSString*) GetPropertyValue: (NSString*) _key;//获取属性值
- (doProperty*) GetProperty: (NSString*) _key;//获取属性对象
#pragma mark -
//virtual
- (BOOL) OnPropertiesChanging:(NSMutableDictionary*) _changedValues;
- (void) OnPropertiesChanged:(NSMutableDictionary*) _changedValues;
- (void) LoadModel: (id<doIPage>) _page : (doJsonNode*) _moduleNode;//装载配置
@end

@interface doUIModuleGetDataDictCallBack : NSObject<doGetDataDictCallBack>
{
@private
    NSMutableDictionary* dictBindDefine;
    doUIModule* uiModule;
}
-(id) init:(NSMutableDictionary *)_dictBindDefine : (doUIModule*) _uiModule;
-(void) Dispose;
@end
@interface doUIModuleGetDataTableCallBack : NSObject<doGetDataTableCallBack>
{
@private
    NSMutableDictionary* dictBindDefine;
    doUIModule* uiModule;
    int rowNumber;
}
-(id) init: (NSMutableDictionary *)_dictBindDefine : (doUIModule*) _uiModule :(int) _rowNumber;
-(void) Dispose;
@end