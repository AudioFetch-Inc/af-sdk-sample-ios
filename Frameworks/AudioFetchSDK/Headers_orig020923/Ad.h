//
//  ad.h
//  audiofetch
//
//  Copyright (c) 2015 Broadcast Vision. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface Ad : NSObject

@property (nonatomic) NSUInteger adId;
@property (strong, nonatomic) NSString *adDescription;
@property (nonatomic) NSTimeInterval delay;

+ (instancetype)factory:(NSUInteger) adId withDescription:(NSString *) description andDelay:(NSTimeInterval) delay;

- (instancetype)initWithId:(NSUInteger) adId withDescription:(NSString *) description andDelay:(NSTimeInterval) delay;
@end