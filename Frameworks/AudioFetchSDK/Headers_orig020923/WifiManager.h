//
//  WifiManager.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WifiManager : NSObject

+ (nonnull instancetype)sharedInstance;
+ (nullable NSDictionary *)getWiFiInfo;
+ (nullable NSString *)getWifiAPName;

@property(readwrite, nonatomic) BOOL monitorWifi;
@property(readonly, nonatomic) BOOL isWifiConnected;

@end
