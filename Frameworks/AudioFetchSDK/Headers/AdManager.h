//
//  AdManager.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
@import UIKit;

@interface AdManager : NSObject <WKNavigationDelegate>
+ (nonnull instancetype)sharedInstance;

- (void)loadClientAds:(nonnull UIViewController *) vc inWebView: (nonnull WKWebView *)webView clientSerial:(nullable NSString *)serial;
- (void)loadAds:(nonnull NSDictionary *)ads;
- (void)loadDefaultAds:(nonnull UIViewController *) vc inWebView: (nonnull WKWebView *) webView;
- (BOOL)displayNextAd;

@property (strong, nonatomic, nullable) UIViewController *viewController;
@property (readwrite, nonatomic, nullable) WKWebView *adView;
@property (readwrite, nonatomic, nullable) NSString *currentSerial;
@property (readwrite, nonatomic) BOOL hasClientAds;
@end
