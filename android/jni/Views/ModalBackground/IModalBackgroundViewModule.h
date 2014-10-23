// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ModalBackgroundViewIncludes.h"

namespace ExampleApp
{
    namespace ModalBackground
    {
        class IModalBackgroundViewModule
        {
        public:
            virtual ~IModalBackgroundViewModule() { }
            
            virtual IModalBackgroundViewController& GetModalBackgroundViewController() const = 0;
        };
    }
}
