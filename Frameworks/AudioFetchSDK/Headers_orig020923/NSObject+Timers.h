//
//  NSObject+Timers.h
//  audiofetch
//
//  Created by Gabriel Bergmiller on 4/8/15.
//  Copyright (c) 2015 Broadcast Vision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Timers)
-(NSTimer *)callSelectorAsync:(SEL) selector object:(id) object delay:(NSTimeInterval) delay;
@end
