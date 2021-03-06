// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include <string>
#include <map>
#include "document.h"
#include "ApplicationInteriorTrackingInfo.h"

namespace ExampleApp
{
    namespace InteriorsPosition
    {
        void ParseIndoorTrackingInfo(std::map<std::string, ApplicationConfig::SdkModel::ApplicationInteriorTrackingInfo>& interiorTrackingInfoList,
                                     const rapidjson::Value& indoorTrackedBuildingsArray);
        
        void TryAndGetInteriorTrackingInfo(
            std::map<std::string, ApplicationConfig::SdkModel::ApplicationInteriorTrackingInfo>& interiorTrackingInfoList,
            const Eegeo::Resources::Interiors::InteriorId& interiorId,
            const Eegeo::Resources::Interiors::MetaData::IInteriorMetaDataService& interiorMetaDataService
            );
        
        const std::string IpsConfig = "ips_config";
    }
}