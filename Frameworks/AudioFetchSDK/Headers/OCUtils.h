//
//  OCUtils.h
//  audioframework
//
//  Objective-C static utilities class
//

#import <Foundation/Foundation.h>
#import <MessageUI/MFMailComposeViewController.h>
#import <UIKit/UIKit.h> 

typedef void(^SendEmailCallback)(BOOL result);

@interface OCUtils : NSObject <MFMailComposeViewControllerDelegate>

+ (nonnull instancetype)sharedInstance;

+ (NSInteger)iOSSubVersion;
+ (NSInteger)iOSMinorVersion;
+ (NSInteger)iOSVersion;

/**
 @brief Returns the machine name (e.g., Carlito's iPhone)
 */
+ (nonnull NSString *)machineName;

/**
 @brief Returns the machine's mac address in hex format, as in: 00:00:00:00:00:00
 */
+ (nonnull NSString *) macAddress;


/**
 @brief Starts an email dialog
 */
+ (void)sendEmailWith:(nonnull UIViewController *) vc
                   To:(nonnull NSArray *)recipients
              Subject:(nonnull NSString *)subject
              Message:(nonnull NSString *)msg
               AsHtml:(BOOL) asHtml
         WithCallback:(null_unspecified SendEmailCallback) callback;


- (BOOL)validateUrl:(nonnull NSString *) url;
@end
