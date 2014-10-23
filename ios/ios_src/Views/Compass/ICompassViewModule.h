// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace ExampleApp
{
    namespace Compass
    {
        class ICompassViewModule
        {
        public:
            
            virtual ~ICompassViewModule() { }
            
            virtual CompassViewController& GetCompassViewController() const = 0;
            virtual CompassView& GetCompassView() const = 0;
        };
    }
}
