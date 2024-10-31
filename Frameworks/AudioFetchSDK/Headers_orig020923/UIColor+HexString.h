//
//  UIColor+HexString.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIColor(HexString)
+ (nullable UIColor *)colorFromHexString:(nonnull NSString *)hexString;
@end
