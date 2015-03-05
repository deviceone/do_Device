

#import <Foundation/Foundation.h>
@class doISourceFS;
@protocol doISourceFS;

@interface doSourceFile : NSObject
{
    @private
    NSString* txtContent;
    NSData * binaryContent;
}
#pragma mark -
- (id) init: (id<doISourceFS>) _sourceFS : (NSString*)_relatedFileName;

#pragma mark -
@property(strong,nonatomic,readonly) NSString *TxtContent;
@property(strong,nonatomic,readonly) id<doISourceFS> SourceFS;
@property(strong,nonatomic,readonly)NSString * FileFullName;
@property (strong,nonatomic)NSData * BinaryContent;


#pragma mark -
-(void) Dispose;
-(void) RefreshContent;
-(void) SaveBinaryData: (NSData *) _data;
-(void) SaveTextData: (NSString *) _data;
-(void) SaveTextData:(NSString*) _data encode: (NSStringEncoding) encoding;
-(NSString*) GetFileFullPath:(NSString*) _relatedFilePath;
@end
