//
//  doUIContainerModel.h
//  DoFrame
//
//  Created by 程序员 on 14/11/25.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//

#import "doUIModule.h"
#import "doUIContainer.h"
#import "doSourceFile.h"
@protocol doIPage;
@interface doUIContainer : NSObject
{
@private
    NSMutableDictionary * dictUIModuleIDs;
    NSString* uniqueKey;
}
#pragma mark -
@property (nonatomic,strong) NSString* ID;
@property (nonatomic,readonly,assign)double  DesignWidth;
@property (nonatomic,readonly,assign)double  DesignHeight;
@property (assign,nonatomic,readonly)double InnerXZoom;
@property (assign,nonatomic,readonly)double InnerYZoom;
@property (nonatomic,readonly,strong)doUIModule  *RootView;
@property (nonatomic,readonly,strong)NSString  *UniqueKey;
@property (nonatomic,readonly,strong)id<doIPage>  CurrentPage;
#pragma mark -
-(id) init: (id<doIPage>) _page;
#pragma mark -
-(void)RegistChildUIModule:(NSString*) _id :(doUIModule *)_uiModule;
- (void)UnregistChildUIModule:(NSString *)_id;
-(doUIModule *)GetChildUIModuleByID:(NSString *)_uiid;
- (void)LoadFromFile:(doSourceFile *)_uiFile : (NSString*) _x : (NSString*) _y;
- (void)LoadFromContent:(NSString *)_content : (NSString*) _x : (NSString*) _y :(NSString*) _filepath;
- (void) LoadDefalutScriptFile:(NSString *)_filePath;
-(void) Dispose;
@end
