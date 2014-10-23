// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "Types.h"
#include "Search.h"
#include "ISearchModule.h"
#include "Location.h"
#include "Web.h"
#include "UrlHelpers.h"
#include "GlobeCameraController.h"
#include "CameraTransitions.h"

namespace ExampleApp
{
    namespace Search
    {
        class SearchModule : public ISearchModule, private Eegeo::NonCopyable
        {
        private:
            ISearchResultRepository* m_pSearchResultRepository;
            Search::ISearchService* m_pSearchService;
            ISearchResultParser* m_pSearchResultParser;
            ISearchQueryPerformer* m_pSearchQueryPerformer;
            ISearchRefreshService* m_pSearchRefreshService;
            
        public:
            SearchModule(const std::string& searchApiKey,
                         Eegeo::Web::IWebLoadRequestFactory& webLoadRequestFactory,
                         Eegeo::Helpers::UrlHelpers::IUrlEncoder& urlEncoder,
                         Eegeo::Camera::GlobeCamera::GpsGlobeCameraController& cameraController,
                         CameraTransitions::ICameraTransitionController& cameraTransitionsController);
            
            ~SearchModule();
            
            ISearchService& GetSearchService() const;
            
            ISearchResultRepository& GetSearchResultRepository() const;
            
            ISearchQueryPerformer& GetSearchQueryPerformer() const;
            
            ISearchRefreshService& GetSearchRefreshService() const;
        };
    }
}
