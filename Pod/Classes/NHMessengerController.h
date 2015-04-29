//
//  NMessengerController.h
//  Pods
//
//  Created by Naithar on 23.04.15.
//
//

@import UIKit;
#import "NHContainerView.h"

@class NHMessengerController;

@protocol NHMessengerControllerDelegate <NSObject>

@optional

- (void)willShowKeyboardForMessenger:(NHMessengerController*)messenger;
- (void)willHideKeyboardForMessenger:(NHMessengerController*)messenger;
- (void)didStartEditingInMessenger:(NHMessengerController*)messenger;

- (void)messenger:(NHMessengerController*)messenger didSendText:(NSString*)text;
- (void)messenger:(NHMessengerController*)messenger didChangeText:(NSString*)text;
- (void)messenger:(NHMessengerController*)messenger didChangeButtonHiddenTo:(BOOL)isHidden;

@end

@interface NHMessengerController : NSObject

@property (nonatomic, weak) id<NHMessengerControllerDelegate> delegate;

@property (nonatomic, assign) UIEdgeInsets textViewInsets;
@property (nonatomic, assign) UIEdgeInsets containerInsets;
@property (nonatomic, assign) UIEdgeInsets separatorInsets;

@property (nonatomic, assign) CGSize sendButtonSize;

@property (strong, readonly, nonatomic) UIView *container;
@property (strong, readonly, nonatomic) id textInputResponder;
@property (strong, readonly, nonatomic) NHContainerView *topView;
@property (strong, readonly, nonatomic) NHContainerView *leftView;
@property (strong, readonly, nonatomic) NHContainerView *bottomView;
@property (strong, readonly, nonatomic) NHContainerView *rightView;
@property (strong, readonly, nonatomic) UIButton *sendButton;
@property (strong, readonly, nonatomic) UIView *separatorView;

@property (nonatomic, assign) UIEdgeInsets initialScrollViewInsets;
@property (nonatomic, assign) UIEdgeInsets additionalInsets;
@property (nonatomic, readonly, assign) UIEdgeInsets keyboardInsets;
@property (nonatomic, readonly, assign) UIEdgeInsets messengerInsets;

- (instancetype)initWithScrollView:(UIScrollView*)scrollView;
- (instancetype)initWithScrollView:(UIScrollView*)scrollView
                     andSuperview:(UIView*)superview;
- (instancetype)initWithScrollView:(UIScrollView*)scrollView
                      andSuperview:(UIView*)superview
                 andTextInputClass:(Class)textInputClass;

- (void)updateMessengerView;
- (void)scrollToBottom;

@end
