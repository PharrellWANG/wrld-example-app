// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#include <vector>
#include "Types.h"
#include "AppRunner.h"
#include "SearchResultModel.h"
#include "SwallowMeetingRoomResultModel.h"
#include "SearchResultPoiViewInterop.h"
#include "SearchResultPoiView.h"

@class SwallowMeetingRoomSearchResultPoiView;

@interface SwallowMeetingRoomSearchResultPoiView : UIView<SearchResultPoiView>
{
    UIViewController* m_pController;
    
    float m_stateChangeAnimationTimeSeconds;
    ExampleApp::Search::SdkModel::SearchResultModel m_model;
    ExampleApp::Search::Swallow::SdkModel::SwallowMeetingRoomResultModel m_meetingRoomModel;
    // using this as temporary storage for updating state of the availability buttons as we don't have a process to update the backend data yet
    std::string m_availability;
    ExampleApp::SearchResultPoi::View::SearchResultPoiViewInterop* m_pInterop;
    
    float m_labelsSectionWidth;
    
    float m_imageWidth;
    float m_imageHeight;
}

- (id)initWithInterop:(ExampleApp::SearchResultPoi::View::SearchResultPoiViewInterop*)pInterop;

- (ExampleApp::SearchResultPoi::View::SearchResultPoiViewInterop*) getInterop;

- (BOOL) consumesTouch:(UITouch *)touch;

- (void) setContent:(const ExampleApp::Search::SdkModel::SearchResultModel*)pModel;

- (void) updateImage:(const std::string&)url :(bool)success bytes:(const std::vector<Byte>*)bytes;

- (void) setFullyActive;

- (void) setFullyInactive;

- (void) setActiveStateToIntermediateValue:(float)activeState;

@property (nonatomic, retain) UIButton* pCloseButton;
@property (nonatomic, retain) UIView* pControlContainer;
@property (nonatomic, retain) UIView* pHeadlineContainer;
@property (nonatomic, retain) UIView* pContentContainer;
@property (nonatomic, retain) UIScrollView* pLabelsContainer;
@property (nonatomic, retain) UIView* pCategoryIconContainer;
@property (nonatomic, retain) UILabel* pTitleLabel;

@property (nonatomic, retain) UIView* pAvailableDivider;
@property (nonatomic, retain) UIButton* pAvailableButton;
@property (nonatomic, retain) UIButton* pAvailableSoonButton;
@property (nonatomic, retain) UIButton* pOccupiedButton;

@property (nonatomic, retain) UIView* pCategoriesHeaderContainer;
@property (nonatomic, retain) UILabel* pCategoriesHeaderLabel;
@property (nonatomic, retain) UILabel* pCategoriesContent;

@property (nonatomic, retain) UIImageView* pPreviewImage;
@property (nonatomic, retain) UIImage* pPlaceholderImage;
@property (nonatomic, retain) UIActivityIndicatorView* pPreviewImageSpinner;
@property (nonatomic, retain) UIView* pImageDivider;
@end
