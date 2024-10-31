//
//  NSString+Base64.h
//  audiofetch
//
//  Created by Michael Honaker on 4/13/15.
//  Copyright (c) 2015 Broadcast Vision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Base64)
- (NSString *)phoneNumber;
- (NSString *)base64Encode;
- (NSString *)base64Decode;
@end
