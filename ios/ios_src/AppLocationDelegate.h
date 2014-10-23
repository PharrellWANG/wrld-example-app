// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#import <CoreLocation/CoreLocation.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
#include "Types.h"
#include "iOSLocationService.h"

@interface AppLocationDelegateLocationListener : NSObject<CLLocationManagerDelegate>
{
    
}
@end

class AppLocationDelegate : protected Eegeo::NonCopyable
{
    AppLocationDelegateLocationListener* m_pAppLocationDelegateLocationListener;
    
public:
	AppLocationDelegate(Eegeo::iOS::iOSLocationService& iOSLocationService,
                        UIViewController& viewController);
    
    ~AppLocationDelegate();
};
