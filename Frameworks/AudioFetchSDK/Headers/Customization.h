//
//  Customization.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Customization : NSObject

// TODO: finish adding video support
+ (instancetype)factoryWithClientId:(NSUInteger) clientId
                           appTitle:(NSString *) appTitle
                          logoImage:(NSString *) logoImage
                     largeLogoImage:(NSString *) largeLogoImage
                    backgroundImage:(NSString *) backgroundImage
                       infoDocument:(NSString *) infoDocument
                    fullPageAdImage:(NSString *) fullPageAdImage
                    fullPageAdVideo:(NSString *) fullPageAdVideo
                     fullPageAdHtml:(NSString *) fullPageAdHtml
                               href:(NSString *) href
                              phone:(NSString *) phone
                              email:(NSString *) email
                           duration:(NSUInteger) duration
                       skipDuration:(NSUInteger) skipDuration
                     adSpaceRssFeed:(NSString *) adSpaceRssFeed
                       primaryColor:(NSString *) primary
                     secondaryColor:(NSString *) secondary
                    backgroundColor:(NSString *) background
                additionalMenuLinks:(NSDictionary<NSString*, NSString *>*) additionalUrls
                       channelIcons:(NSDictionary<NSString*, NSString *>*) icons;

- (instancetype)initWithClientId:(NSUInteger) clientId
                        appTitle:(NSString *) appTitle
                       logoImage:(NSString *) logoImage
                  largeLogoImage:(NSString *) largeLogoImage
                 backgroundImage:(NSString *) backgroundImage
                    infoDocument:(NSString *) infoDocument
                 fullPageAdImage:(NSString *) fullPageAdImage
                 fullPageAdVideo:(NSString *) fullPageAdVideo
                  fullPageAdHtml:(NSString *) fullPageAdHtml
                            href:(NSString *) href
                           phone:(NSString *) phone
                           email:(NSString *) email
                        duration:(NSUInteger) duration
                    skipDuration:(NSUInteger) skipDuration
                  adSpaceRssFeed:(NSString *) adSpaceRssFeed
                    primaryColor:(NSString *) primary
                  secondaryColor:(NSString *) secondary
                 backgroundColor:(NSString *) background
             additionalMenuLinks:(NSDictionary<NSString*, NSString *>*) additionalUrls
                    channelIcons:(NSDictionary<NSString*, NSString *>*) icons;


@property (readonly) BOOL hasFullPageAd;
@property (nonatomic) NSUInteger clientId;
@property (nonatomic, strong) NSString *appTitle;
@property (nonatomic, strong) NSString *logoImageUrl;
@property (nonatomic, strong) NSString *largeLogoImageUrl;
@property (nonatomic, strong) NSString *backgroundImageUrl;
@property (nonatomic, strong) NSString *infoDocumentUrl;
@property (nonatomic, strong) NSString *fullPageAdImageUrl;
@property (nonatomic, strong) NSString *fullPageAdHref;
@property (nonatomic, strong) NSString *fullPageAdPhone;
@property (nonatomic, strong) NSString *fullPageAdEmail;
@property (nonatomic, strong) NSString *fullPageAdHtml;
@property (nonatomic, strong) NSString *fullPageAdVideoUrl;
@property (nonatomic) NSUInteger fullPageAdDuration;
@property (nonatomic) NSUInteger fullPageSkipDuration;
@property (nonatomic, strong) NSString *adSpaceRssFeedUrl;
@property (nonatomic, strong) NSString *primaryColor;
@property (nonatomic, strong) NSString *secondaryColor;
@property (nonatomic, strong) NSString *backgroundColor;
@property (nonatomic, strong) NSDictionary<NSString*, NSString *> *additionalMenuLinkUrls;
@property (nonatomic, strong) NSDictionary<NSString*, NSString *> *channelIcons;
@end
