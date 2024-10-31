//
//  Report.h - Model class for sending reports to server
//  audiofetch
//
//  Copyright (c) 2015 Broadcast Vision. All rights reserved.
//

#import <Foundation/Foundation.h>

#define EVENT_TRACK_START @"start"
#define EVENT_TRACK_END @"end"
#define EVENT_TRACK_PING @"ping"
#define EVENT_TRACK_ADS @"ads"

#define REPORT_CHANNEL_DEFAULT -1

typedef enum {
    START = 0,
    END,
    PING,
    ADS
} ReportType;

@interface Report : NSObject
- (instancetype)initWithSerial:(NSString *) apbSerial
                            ip:(NSString *) apbIp
                       channel:(NSInteger) apbChannel
                           lat:(NSString *) latitude
                           lng:(NSString *) longitude
                          uuid:(NSString *) uuidString
                        device:(NSString *) deviceMake
                         model:(NSString *) deviceModel
                        system:(NSString *) deviceSystem
                       version:(NSString *) deviceVersion
                     appBundle:(NSString *) appBundle
                    appVersion:(NSString *) appVersion
                          type:(ReportType) reportType;

@property (strong, nonatomic) NSString *apbSerial;
@property (strong, nonatomic) NSString *apbIp;
@property (nonatomic) NSInteger apbChannel;
@property (strong, nonatomic) NSString *lat;
@property (strong, nonatomic) NSString *lng;
@property (strong, nonatomic) NSString *uuid;
@property (strong, nonatomic) NSString *device;
@property (strong, nonatomic) NSString *model;
@property (strong, nonatomic) NSString *system;
@property (strong, nonatomic) NSString *version;
@property (strong, nonatomic) NSString *appBundle;
@property (strong, nonatomic) NSString *appVersion;
@property (strong, nonatomic) NSString *extra;

@property (readwrite, nonatomic) ReportType reportType;
@property (readonly) NSString *reportTypeString;

@property (readonly) NSMutableDictionary *reportAsDictionary;
@property (readonly) NSString *reportAsJson;
@end
