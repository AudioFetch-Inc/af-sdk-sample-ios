//
//  CustomizationManager.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#import "afetch_framework_extern.h"
#import "Customization.h"


AFETCH_FRAMEWORK_EXTERN BOOL const AF_CUSTOMIZATIONS_ENABLED;

@import UIKit;

typedef void(^CustomizationsCompletionHandler)(BOOL hasCustomizations, BOOL hasFullPageAd, BOOL hasFullPageVideo);
typedef void(^FullPageAdClickedCompletionHandler)(void);

@interface CustomizationManager : NSObject <WKNavigationDelegate>
+ (nonnull instancetype)sharedInstance;

- (void)loadFullPageAd:(nonnull UIViewController *) vc
             inWebView: (nonnull WKWebView *)webView
     completionHandler:(nonnull FullPageAdClickedCompletionHandler) handler;

- (void)loadCustomizations:(nonnull NSString *)serial
         completionHandler:(nonnull CustomizationsCompletionHandler) handler;

- (void)showCustomizationActionSheet;
- (void)showAdActionSheet:(nonnull NSDictionary *) dict;

- (nullable UIImage *)getMediaCenterAppIcon:(nonnull UIImage *)logoImage;

@property (readwrite, nonatomic) BOOL isCustomizationEnabled;
@property (strong, nonatomic, null_unspecified) Customization *customization;
@property (strong, nonatomic, nullable) UIViewController *viewController;
@property (readwrite, nonatomic, nullable) WKWebView *adView;
@property (readwrite, nonatomic, nullable) NSString *currentSerial;

@property (readonly, nullable) NSString *appTitle;
@property (readonly, nonnull) UIColor *primaryColor;
@property (readonly, nonnull) UIColor *secondaryColor;
@property (readonly, nonnull) UIColor *backgroundColor;

@property (readonly, nullable) NSURL *infoDocumentUrl;
@property (readonly, nullable) NSURL *customLogoUrl;
@property (readonly, nullable) NSURL *largeLogoUrl;
@property (readonly, nullable) NSURL *backgroundImageUrl;
@property (readonly, nullable) NSString *fullPageAdHtml;
@property (readonly, nullable) NSString *fullPageAdVideo;
@property (readonly, nullable) NSString *fullPageAdEmail;
@property (readonly, nullable) NSString *fullPageAdPhone;
@property (readonly, nullable) NSString *fullPageAdWebsite;
@property (readonly) double fullPageAdDuration;
@property (readonly) double fullPageSkipDuration;
@property (readonly, nullable) NSString *adSpaceRssFeedUrl;
@property (readonly, nullable) NSDictionary<NSString *, NSURL *> *additionalMenuLinkUrls;
@property (readonly, nullable) NSDictionary<NSString *, NSURL *> *channelIcons;

@property (readonly) BOOL hasCustomLogo;
@property (readonly) BOOL hasLargeLogo;
@property (readonly) BOOL hasBackgroundImage;
@property (readonly) BOOL hasAdSpaceRssFeed;
@property (readonly) BOOL hasInfoDocument;
@property (readonly) BOOL hasAdditionalMenuLinks;
@property (readonly) BOOL hasChannelIcons;

@property (readonly) BOOL hasPrimaryColor;
@property (readonly) BOOL hasSecondaryColor;
@property (readonly) BOOL hasBackgroundColor;

@property (readonly) BOOL isActionSheetActive;

@property (readwrite, nonatomic) BOOL hasCustomization;
@property (readwrite, nonatomic) BOOL hasFullPageAd;
@property (readwrite, nonatomic) BOOL hasFullPageVideo;

@property (readwrite, nonatomic) BOOL hasUserInitiatedPhoneCall;
@property (readonly) BOOL isPhoneCallActive;
@property (readonly) BOOL isFullPageAdPhoneCallActive;
@end
