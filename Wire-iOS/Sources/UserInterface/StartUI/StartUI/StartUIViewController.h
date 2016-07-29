// 
// Wire
// Copyright (C) 2016 Wire Swiss GmbH
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see http://www.gnu.org/licenses/.
// 


#import <UIKit/UIKit.h>

@class ZMConversation, PeopleInputController;

typedef NS_ENUM(NSUInteger, StartUIAction) {
    StartUIActionCreateOrOpenConversation,
    StartUIActionCall,
    StartUIActionVideoCall,
    StartUIActionPostPicture,
};

@protocol StartUIDelegate;

@interface StartUIViewController : UIViewController

- (instancetype)initWithSearchDirectoryClass:(Class)searchDirectoryClass;
@property (nonatomic, weak) id <StartUIDelegate> delegate;
@property (nonatomic, weak) PeopleInputController *peopleInputController;
@property (nonatomic, readonly) UIScrollView *scrollView;

- (void)showKeyboardIfNeeded;

@end


@protocol StartUIDelegate <NSObject>
- (void)startUIDidCancel:(StartUIViewController *)startUI;
/// NSSet of ZMUsers
- (void)startUI:(StartUIViewController *)startUI didSelectUsers:(NSSet *)users forAction:(StartUIAction)action;
@optional
- (void)startUI:(StartUIViewController *)startUI didSelectConversation:(ZMConversation *)conversation;
@end