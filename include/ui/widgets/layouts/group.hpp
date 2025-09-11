#pragma once
#ifndef UI_WIDGETS_LAYOUTS_GROUP_HPP_
#define UI_WIDGETS_LAYOUTS_GROUP_HPP_

#include "ui/settings/group_widget_settings.hpp"
#include "ui/widgets/base_widget.hpp"
#include "ui/widgets/widget_container.hpp"

namespace UI::Widgets::Layouts
{
    class Group : public BaseWidget, public WidgetContainer
    {
    public:
        Group(const Settings::GroupWidgetSettings& groupSettings = Settings::GroupWidgetSettings { });
        virtual ~Group() override;

        Group(const Group& other)             = delete;
        Group(Group&& other)                  = delete;
        Group& operator=(const Group& other)  = delete;
        Group& operator=(const Group&& other) = delete;

        void SetSettings(const Settings::GroupWidgetSettings& settings);
        Settings::GroupWidgetSettings GetSettings() const;

        void ScrollToBottom();
        void ScrollToTop();
        void ScrollToRight();
        void ScrollToLeft();

        bool IsScrolledToBottom() const;
        bool IsScrolledToTop()    const;
        bool IsScrolledToRight()  const;
        bool IsScrolledToLeft()   const;

    protected:
        virtual void DrawImpl() override;

        Settings::GroupWidgetSettings m_groupSettings;

    private:
        bool m_mustScrollToBottom = false;
        bool m_mustScrollToTop    = false;
        bool m_mustScrollToRight  = false;
        bool m_mustScrollToLeft   = false;
    };
}

#endif // UI_WIDGETS_LAYOUTS_GROUP_HPP_
