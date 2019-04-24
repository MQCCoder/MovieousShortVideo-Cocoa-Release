//
//  MSVImageStickerEditorEffect.h
//  MovieousShortVideo
//
//  Created by Chris Wang on 2018/10/24.
//  Copyright © 2018 Movieous Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSVBasicEditorEffect.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Image sticker effects
 */
@interface MSVImageStickerEditorEffect : MovieousImageStickerCaptureEffect
<
MSVBasicEditorEffect
>

/**
 * @brief User-defined ID field, business usage is used to distinguish objects
 */
@property (nonatomic, strong) NSString *ID;

/**
 * @brief The time interval for applying an external filter in the main track
 */
@property (nonatomic, assign) MovieousTimeRange timeRangeAtMainTrack;

- (instancetype)initWithImageStickerCaptureEffect:(MSVImageStickerEditorEffect *)imageStickerCaptureEffect;

@end

NS_ASSUME_NONNULL_END
