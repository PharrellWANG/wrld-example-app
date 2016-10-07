// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "WorldPinOnMapViewModule.h"
#include "WorldPinOnMapView.h"
#include "WorldPinOnMapController.h"
#include "AndroidAppThreadAssertionMacros.h"

namespace ExampleApp
{
    namespace WorldPins
    {
        namespace View
        {
			void WorldPinOnMapViewModule::Register(const TContainerBuilder& builder)
			{
				builder->registerType<WorldPinOnMapView>().as<IWorldPinOnMapView>().singleInstance();
			}

			void WorldPinOnMapViewModule::RegisterUiLeaves()
			{
				ASSERT_UI_THREAD
				RegisterLeaf<IWorldPinOnMapView>();
			}
        }
    }
}
