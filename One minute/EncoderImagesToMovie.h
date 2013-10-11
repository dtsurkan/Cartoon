//
//  EncoderImagesToMovie.h
//  One minute
//
//  Created by Vladimir Boychentsov on 5/20/11.
//  Copyright 2011 www.injoit.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#import "WorkspaceFileListViewer.h"

@interface EncoderImagesToMovie : UIViewController <MFMailComposeViewControllerDelegate, UIActionSheetDelegate> {
    IBOutlet UIProgressView *progressView;
    float delta;
    
    IBOutlet UILabel *fpsLabel;
    IBOutlet UISlider *fpsSlider;
    IBOutlet UIImageView *imgscreen;
    
    NSString *currentWorkspace;
    
    WorkspaceFileListViewer *fileViewerController;
}
- (IBAction) createMovie;

- (IBAction) touchUpInsideFpsSlider;

- (void) writeImagesAsMovie:(NSArray *)array toPath:(NSString*)path;

- (void) setWorkspaceName: (NSString*)nameW;

@end
