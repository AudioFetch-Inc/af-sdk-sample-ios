//
//  ButtonActionSheet.h
//
//  Author: Beach Cities Software, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^ButtonActionSheetCompletionHandler)(NSInteger buttonIndex);

@interface ButtonActionSheet : NSObject <UIActionSheetDelegate>

@property (strong, nonatomic, null_unspecified) UIAlertController *alertController;

+ (void)setTintColor:(nonnull UIColor *)color;
+ (nonnull UIColor *)tintColor;

+ (nonnull instancetype)ShowButtonActionSheetWithHandler:(nonnull ButtonActionSheetCompletionHandler) handler
                                                   Title:(nullable NSString *)title
                                       cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                  destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                       otherButtonTitles:(nullable NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

+ (nonnull instancetype)ShowButtonActionSheetWithHandler:(nonnull ButtonActionSheetCompletionHandler) handler
                                                   Title:(nullable NSString *)title
                                       cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                  destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                  otherButtonTitlesArray:(nullable NSArray *)otherButtonTitles;

- (nonnull instancetype)initWithHandler:(nonnull ButtonActionSheetCompletionHandler) handler
                                  Title:(nullable NSString *)title
                      cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                 destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                      otherButtonTitles:(nullable NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

- (nonnull instancetype)initWithHandler:(nonnull ButtonActionSheetCompletionHandler) handler
                                  Title:(nullable NSString *)title
                      cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                 destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                 otherButtonTitlesArray:(nullable NSArray *)otherButtonTitles;
@end
