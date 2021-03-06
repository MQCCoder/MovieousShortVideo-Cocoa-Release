//
//  MSVClip.h
//  MovieousShortVideo
//
//  Created by Chris Wang on 2019/4/13.
//  Copyright © 2019 Movieous Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSVTypeDefines.h"
#import <MovieousBase/MovieousBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The base class used to specify basic clip logic.
 */
@interface MSVClip : NSObject
<
NSCopying
>

/**
 * Initialize a clip.
 *
 * @param type Type of clip.
 * @param URL The file path of the clip supports local files only.
 * @param outError If an error occurs, return the error that occurred.
 *
 * @return If the initialization is successful, the completed object is returned, otherwise returns nil.
 */
- (instancetype _Nullable)initWithType:(MSVClipType)type URL:(NSURL *)URL error:(NSError *_Nullable *_Nullable)outError;

/**
 * Initialize a clip of an audio and video type using AVAsset.
 *
 * @param asset AVAsset object used to create the clip.
 * @param outError If an error occurs, return the error that occurred.
 *
 * @return If the initialization is successful, the completed object is returned, otherwise returns nil.
 */
- (instancetype _Nullable)initWithAsset:(AVAsset *)asset error:(NSError *_Nullable *_Nullable)outError;

/**
 * Initialize a clip of a image type using UIImage.
 *
 * @param image UIImage object used to create the clip.
 * @param duration Image duration.
 * @param outError If an error occurs, return the error that occurred.
 *
 * @return If the initialization is successful, the completed object is returned, otherwise returns nil.
 */
- (instancetype _Nullable)initWithImage:(UIImage *)image duration:(NSTimeInterval)duration error:(NSError *_Nullable *_Nullable)outError;

/**
 * Initialize a clip with another clip.
 *
 * @param clip The clip used to intialize the clip.
 *
 * @return the initialized instance.
 */
- (instancetype)initWithClip:(MSVClip *)clip;

/**
 * User-defined ID field, you can use this property to store information you want to associate to this object.
 */
@property (nonatomic, strong) NSString *ID;

/**
 * Type of the clip object.
 */
@property (nonatomic, assign, readonly) MSVClipType type;

/**
 * Media file URL.
 */
@property (nonatomic, strong, readonly) NSURL *URL;

/**
 * The frame in the source video spece which will be used to display in destination video.
 * The default is CGRectInfinite which means all part of the source video is used
 */
@property (nonatomic, assign) CGRect sourceDisplayFrame;

/**
 * The frame in destination video space you want to place the source display video.
 * The default is CGRectNull which means the total destination video space is used
 */
@property (nonatomic, assign) CGRect destDisplayFrame;

/**
 * The angle you want to rotate the display area, rotation will be applied after the source video has been placed correctly in the destDisplayFrame, and the anchor point is at the center of the destDisplayFrame in the destination video space.
 */
@property (nonatomic, assign) float rotateAngle;

/**
 * The scaling mode you want to use if the aspect ratio of sourceDisplayFrame and destDisplayFrame are not equal.
 */
@property (nonatomic, assign) MovieousScalingMode scalingMode;

/**
 * The duration of the clip in the main track, when clip type is MSVClipTypeAV, the durationAtMainTrack parameter and speed affect each other, adjust durationAtMainTrack will affect speed, the specific operational relationship is： speed = timeRange.duration / durationAtMainTrack.
 */
@property (nonatomic, assign) NSTimeInterval durationAtMainTrack;


// The following parameters are only valid for the clip of the MSVClipTypeAV type.
#pragma mark - video properties
/**
 * The AVAsset object generated by the audio and video media files, you can get some required parameters here.
 */
@property (nonatomic, strong, readonly) AVAsset *asset;

/**
 * Intercepting the time range that used in the media clip.
 * The default is kMovieousTimeRangeDefault which stands for the full duration of the source clip.
 *
 * @warning This time range refers to the time range without the fast and slow processing and reverses processing, Also, if timeRange.startTime + timeRange.duration > total media duration,  the excess part will be ignored.
 */
@property (nonatomic, assign) MovieousTimeRange timeRange;

/**
 * Clip speed of the clip to be recorded.
 * the default is 1.0.
 *
 * @discussion
 * Recommend configurations:
 * very fast：2.0.
 * fast：1.5.
 * normal：1.0.
 * slow：0.75.
 * very slow：0.5.
 */
@property (nonatomic, assign) float speed;

/**
 * The volume of the media audio.
 * The default is the preferredVolume that comes with the media file.
 */
@property (nonatomic, assign) float volume;

// The following parameters are only valid for the clip of the MSVClipTypeImage type.
#pragma mark - image properties
/**
 * Image object.
 */
@property (nonatomic, assign, readonly) UIImage *image;

/**
 * Refresh inner Asset objects，need to be called when received `AVAudioSessionMediaServicesWereResetNotification` notification.
 */
- (void)refreshAsset;

@end

NS_ASSUME_NONNULL_END
