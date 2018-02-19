// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "ISearchResultPoiView.h"
#include "ISearchResultPoiViewModel.h"
#include "ICallback.h"
#include "Types.h"
#include "BidirectionalBus.h"
#include "SearchResultModel.h"
#include "IMetricsService.h"
#include "SearchResultPoiController.h"
#include "InteriorSelectionModel.h"
#include "ISearchMenuView.h"

namespace ExampleApp
{
    namespace SearchResultPoi
    {
        namespace View
        {
            class DesktopSearchResultPoiController : public SearchResultPoiController
            {
               

              //  Eegeo::Helpers::TCallback0<DesktopSearchResultPoiController> m_onPinCreationSelected;
                void OnPinCreationSelectedOrSearchCleared();

                Eegeo::Resources::Interiors::InteriorSelectionModel& m_interiorSelectionModel;
                Eegeo::Helpers::TCallback1<DesktopSearchResultPoiController, const Eegeo::Resources::Interiors::InteriorId> m_interiorChangedCallback;
                Eegeo::Helpers::TCallback1<DesktopSearchResultPoiController, const AppModes::AppModeChangedMessage&> m_appModeChangedHandler;

                void OnInteriorSelectionChanged(const Eegeo::Resources::Interiors::InteriorId& interiorId);

                void OnAppModeChangedMessage(const AppModes::AppModeChangedMessage& message);

                SearchMenu::View::ISearchMenuView& m_searchMenuView;
                Eegeo::Helpers::TCallback0<DesktopSearchResultPoiController> m_searchClearedCallback;

            public:
                DesktopSearchResultPoiController(ISearchResultPoiView& view,
                    ISearchResultPoiViewModel& viewModel,
                    SearchMenu::View::ISearchMenuView& searchMenuView,
                    ExampleAppMessaging::TMessageBus& messageBus,
                    Metrics::IMetricsService& metricsService,
                    Eegeo::Resources::Interiors::InteriorSelectionModel& interiorSelectionModel);

                virtual ~DesktopSearchResultPoiController();

                void OnViewOpened();
            };
        }
    }
}
