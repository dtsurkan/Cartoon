//
//  WorkspaceItem.m
//  One minute
//
//  Created by Vladimir Boychentsov on 5/21/11.
//  Copyright 2011 www.injoit.com. All rights reserved.
//

#import "WorkspaceItem.h"
#import <QuartzCore/QuartzCore.h>

@implementation WorkspaceItem

@synthesize delegate;


- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        
        [[self layer] setBorderWidth:2];
        [[self layer] setCornerRadius:15];
        [[self layer] setBorderColor:[UIColor whiteColor].CGColor];
        [self setBackgroundColor:[UIColor darkGrayColor]];
        [self setClipsToBounds:YES];
    }
    return self;
}

- (void) setTitleName: (NSString*) _title {
    title = [_title retain];
    
    if (labelName == nil) {
        labelName = [[UILabel alloc] initWithFrame:CGRectMake(7, 5, self.frame.size.width-14, 14)];
        [labelName setFont:[UIFont systemFontOfSize:10]];
        [labelName setText:title];
        [labelName setTextColor:[UIColor lightGrayColor]];
        [labelName setBackgroundColor:[UIColor clearColor]];
    }
    [self addSubview:labelName];
    
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(2, 22, self.frame.size.width-4, self.frame.size.height-22)];
    [self addSubview:imgView];
    
    NSFileManager *manager = [NSFileManager defaultManager];
    NSString *documents = [[Utils documentsDirectory] stringByAppendingPathComponent:title];
    [manager removeItemAtPath:[documents stringByAppendingPathComponent:@"movie.mov"] error:nil];
    NSArray *files = [manager contentsOfDirectoryAtPath:documents error:nil];
    
    if ([files count] > 0) {
        NSString *filename = [documents stringByAppendingPathComponent:[files objectAtIndex:0]];
        UIImage *first = [UIImage imageWithContentsOfFile:filename];
        [imgView setImage:first];        
    }
    
    
    [imgView release];
    
}


- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [[self layer] setBorderColor:[UIColor lightGrayColor].CGColor];
    [self setBackgroundColor:[UIColor blackColor]];
}

- (void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    [[self layer] setBorderColor:[UIColor whiteColor].CGColor];
    [self setBackgroundColor:[UIColor darkGrayColor]];
    [delegate performSelector:@selector(movieCreatorOfWorkspace:) withObject:title];
}
- (void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    [[self layer] setBorderColor:[UIColor whiteColor].CGColor];
    [self setBackgroundColor:[UIColor darkGrayColor]];
}



/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

- (void)dealloc
{
    [title release];
    [super dealloc];
}

@end
