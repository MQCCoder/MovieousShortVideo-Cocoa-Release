//
//  MSVImageGenerator.h
//  MovieousShortVideo
//
//  Created by Chris Wang on 2019/3/31.
//  Copyright © 2019 Movieous Team. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <MovieousBase/MovieousBase.h>

NS_ASSUME_NONNULL_BEGIN

@class MSVImageGeneratorResult;

/**
 * Image generation completed block.
 *
 * @param results The generation result array.
 * @param result The generation result status.
 * @param error The error object if any error occurs.
 */
typedef void (^MSVImageGeneratorCompletionHandler)(NSArray<MSVImageGeneratorResult *> *_Nullable results, AVAssetImageGeneratorResult result, NSError *_Nullable error);

/**
 * The generated result.
 */
@interface MSVImageGeneratorResult : NSObject

/**
 * The time for which you requested an image.
 */
@property (nonatomic, assign) NSTimeInterval requestedTime;

/**
 * The actual time of the snapshot.
 */
@property (nonatomic, assign) NSTimeInterval actualTime;

/**
 * The image that was generated.
 */
@property (nonatomic, strong) UIImage *image;

@end

/**
 * The image generator used to generate snapshots.
 */
@interface MSVImageGenerator : NSObject

/**
 * The timeRange within which snapshots will be generated.
 */
@property (nonatomic, assign) MovieousTimeRange timeRange;

/**
 * Count of image.
 */
@property (nonatomic, assign) NSUInteger imageCount;

/**
 * TimeInterval of the generation of snapshots.
 */
@property (nonatomic, assign, readonly) NSTimeInterval timeInterval;

/**
 * The inner AVAsset of the image generator.
 */
@property (nonatomic, strong) AVAsset *innerAsset;

/**
 * The inner AVAssetImageGenerator instance, you can use this to do your own image genration.
 */
@property (nonatomic, strong, readonly) AVAssetImageGenerator *innerImageGenerator;

/**
 * Generate images use parameters of the generator.
 *
 * @param handler A block called when an image generate request is completed.
 */
- (void)generateImagesWithCompletionHandler:(MSVImageGeneratorCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
