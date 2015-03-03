//
//  doDefines.h
//  DoCore
//
//  Created by 刘吟 on 14/12/6.
//  Copyright (c) 2014年 DongXian. All rights reserved.
//
#define ISLANDSCAPE @"isLandscape"
#define ISDEBUG @"isDebug"

#define SUPPRESS_PERFORM_SELECTOR_LEAK_WARNING(code)                        \
_Pragma("clang diagnostic push")                                        \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")     \
code;                                                                   \
_Pragma("clang diagnostic pop")                                         \

#define IsPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define IOS_7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f)

#define IOS_8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0f)


#define APP (AppDelegate*)[UIApplication sharedApplication].delegate

#define DEVICE_WIDTH  ([[UIScreen mainScreen] bounds].size.width)

#define DEVICE_HEIGHT (([[UIScreen mainScreen] bounds].size.height)-0)

#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define UIFONT(S) [UIFont systemFontOfSize:S]

