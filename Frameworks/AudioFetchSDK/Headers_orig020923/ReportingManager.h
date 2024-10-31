//
//  ReportingManager.h
//  audiofetch
//
//  Copyright © 2015 AudioFetch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Report.h"
#import "DownloadManager.h"
#import <CoreLocation/CoreLocation.h>

typedef void(^ReportingManagerCompletionHandler)(BOOL success);

/**
 @brief Handles reporting for various events
 */
@interface ReportingManager : NSObject

@property (strong, nonatomic, nullable) NSString *sessionId;

+ (nonnull instancetype)sharedInstance;

+ (void)setUserLocation:(nullable CLLocation *) location;
+ (nullable CLLocation *) userLocation;

+ (void)setCurrentHost:(nonnull NSString *)ip
                serial:(nonnull NSString *)serial
               channel:(NSInteger) channel;

+ (void)sendStartReport;
+ (void)sendPingReport;
+ (void)sendAdsReport:(nonnull NSArray *) ads;
+ (void)sendAdClickedReport:(int) adId;
+ (BOOL)isReportingEnabled;

+ (void)sendStartReportWithIp:(nonnull NSString *) ip
                       serial:(nonnull NSString *) serial;
+ (void)sendEndReportWithIp:(nonnull NSString *) ip
                     serial:(nonnull NSString *) serial;
+ (void)sendEndReport;
+ (void)sendPingReportWithIp:(nonnull NSString *) ip
                      serial:(nonnull NSString *) serial
                     channel:(NSInteger) channel;
+ (void)sendAdsReport:(nonnull NSArray *) ads
              channel:(NSInteger) channel;
+ (void)sendAdClickedReport:(NSInteger) adId
                    channel:(NSInteger) channel;


- (void)sendReport:(nonnull Report *) report
          callback:(nullable ReportingManagerCompletionHandler) handler;

- (void)sendWithSerial:(nonnull NSString *) apbSerial
                    ip:(nonnull NSString *) apbIp
                  type:(ReportType) reportType
              callback:(nullable ReportingManagerCompletionHandler) handler;

- (void)sendWithSerial:(nonnull NSString *) apbSerial
                          ip:(nonnull NSString *) apbIp
                     channel:(NSInteger) apbChannel
                        type:(ReportType) reportType
                    callback:(nullable ReportingManagerCompletionHandler) handler;

- (void)sendWithSerial:(nonnull NSString *) apbSerial
                    ip:(nonnull NSString *) apbIp
               channel:(NSInteger) apbChannel
                  type:(ReportType) reportType
                 extra:(nullable NSString *) extra
              callback:(nullable ReportingManagerCompletionHandler) handler;

- (void)deallocReporting;
@end
