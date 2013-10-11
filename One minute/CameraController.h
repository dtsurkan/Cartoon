//
//  CameraController.m
//  One minute
//
//  Created by Vladimir Boychentsov on 5/20/11.
//  Copyright 2011 www.injoit.com. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CoreMedia.h>


@class BlueGradientButton;

/*!
 @class	CameraController 

 @brief    Controller to demonstrate how we can have a direct access to the camera using the iPhone SDK 4
 */
@interface CameraController : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate> {
	AVCaptureSession *_captureSession;
	UIImageView *_imageView;
	CALayer *_customLayer;
	AVCaptureVideoPreviewLayer *_prevLayer;
    
    AVCaptureConnection *_conn;
    
    IBOutlet UISlider *slider;
    IBOutlet UILabel *counter;

    IBOutlet UISlider *sliderShot;
    IBOutlet UILabel *countShot;
    
    IBOutlet BlueGradientButton *startButton;
    IBOutlet BlueGradientButton *doneButton;
    
    IBOutlet UIActivityIndicatorView *indicator;

    IBOutlet UISwitch *hdSw;
    IBOutlet UILabel *hdLabel;
    
    int imageCounter;
    int intervalShot;
    
    UITextField *nameWorkspaceField;
    
    NSString *workspaceName;
    
}

/*!
 @brief	The capture session takes the input from the camera and capture it
 */
@property (nonatomic, retain) AVCaptureSession *captureSession;

/*!
 @brief	The UIImageView we use to display the image generated from the imageBuffer
 */
@property (nonatomic, retain) IBOutlet UIImageView *imageView;
/*!
 @brief	The CALayer we use to display the CGImageRef generated from the imageBuffer
 */
@property (nonatomic, retain) CALayer *customLayer;
/*!
 @brief	The CALAyer customized by apple to display the video corresponding to a capture session
 */
@property (nonatomic, retain) AVCaptureVideoPreviewLayer *prevLayer;

/*!
 @brief	This method initializes the capture session
 */
//- (void)initCapture;
- (IBAction) capture10;
- (IBAction) initCapture;
- (IBAction) startCapture;
- (IBAction) doneRecord;

- (IBAction) touchUpSliderShot;

- (void) saveCurrentPicture;
- (void) recreateCapture;


@end