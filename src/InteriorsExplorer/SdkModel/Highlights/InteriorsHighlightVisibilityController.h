// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Search.h"
#include "Interiors.h"
#include "InteriorsExplorer.h"
#include "Rendering.h"
#include "BidirectionalBus.h"
#include <string>
#include <vector>
#include <map>

namespace ExampleApp
{
    namespace InteriorsExplorer
    {
        namespace SdkModel
        {
            namespace Highlights
            {
                
                class InteriorsHighlightVisibilityController : protected Eegeo::NonCopyable
                {
                public:
                    InteriorsHighlightVisibilityController(Eegeo::Resources::Interiors::InteriorController& interiorController,
                                                           Search::SdkModel::ISearchService& searchService,
                                                           Search::SdkModel::ISearchQueryPerformer& searchQueryPerformer,
                                                           Search::SdkModel::ISearchResultRepository& searchResultRepository,
                                                           Eegeo::Resources::Interiors::Entities::IInteriorsLabelController& labelController,
                                                           ExampleAppMessaging::TMessageBus& messageBus);
                    
                    ~InteriorsHighlightVisibilityController();
                    
                private:
                    void OnSearchPerformed(const Search::SdkModel::SearchQuery& query);
                    void OnSearchResultsLoaded(const Search::SdkModel::SearchQuery& query, const std::vector<Search::SdkModel::SearchResultModel>& results);
                    void OnSearchResultCleared();
                    
                    void OnInteriorVisibilityChanged();
                    void OnAvailabilityChanged(const ExampleApp::SearchResultOnMap::SearchResultMeetingAvailabilityChanged& message);
                    
                    void ConfigureRenderableForAvailability(Eegeo::Rendering::Renderables::InteriorHighlightRenderable& renderable, const std::string& availability);
                    void DeactivateHighlightRenderables();
                    void AddHighlight(Eegeo::Rendering::Renderables::InteriorHighlightRenderable& renderable);
                    
                    void ShowLabelsForResults(const std::vector<Search::SdkModel::SearchResultModel>& results);
                    void ShowLabelsForCurrentResults();
                    void DeactivateLabels();
                    
                    Eegeo::Resources::Interiors::InteriorController& m_interiorController;
                    Eegeo::Resources::Interiors::Entities::IInteriorsLabelController& m_interiorslabelsController;
                    Search::SdkModel::ISearchService& m_searchService;
                    Search::SdkModel::ISearchQueryPerformer& m_searchQueryPerformer;
                    Search::SdkModel::ISearchResultRepository& m_searchResultRepository;
                    ExampleAppMessaging::TMessageBus& m_messageBus;
                    
                    Eegeo::Helpers::TCallback1<InteriorsHighlightVisibilityController, const Search::SdkModel::SearchQuery&> m_searchPerformedHandler;
                    Eegeo::Helpers::TCallback2<InteriorsHighlightVisibilityController, const Search::SdkModel::SearchQuery&, const std::vector<Search::SdkModel::SearchResultModel>&> m_searchResultsHandler;
                    Eegeo::Helpers::TCallback0<InteriorsHighlightVisibilityController> m_searchResultsClearedHandler;
                    Eegeo::Helpers::TCallback0<InteriorsHighlightVisibilityController> m_interiorVisibilityChangedHandler;
                    
                    Eegeo::Helpers::TCallback1<InteriorsHighlightVisibilityController, const SearchResultOnMap::SearchResultMeetingAvailabilityChanged&>m_availabilityChangedHandlerBinding;
                    
                    std::map<std::string, std::string> m_highlightAvailabilityData;
                    std::map<std::string, Eegeo::Rendering::Renderables::InteriorHighlightRenderable*> m_currentHighlightRenderables;
                };
            }
        }
    }
}

