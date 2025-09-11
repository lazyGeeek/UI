#pragma once
#ifndef UI_PANELS_BASE_PANEL_HPP_
#define UI_PANELS_BASE_PANEL_HPP_

#include <string>

#include "ui/drawable_interface.hpp"
#include "ui/widgets/widget_container.hpp"

namespace UI::Panels
{
    class BasePanel : public IDrawable, public Widgets::WidgetContainer
    {
    public:
        BasePanel();
        virtual ~BasePanel() = default;

        BasePanel(const BasePanel& other)             = delete;
        BasePanel(BasePanel&& other)                  = delete;
        BasePanel& operator=(const BasePanel& other)  = delete;
        BasePanel& operator=(const BasePanel&& other) = delete;

        virtual bool Draw() override;
        const std::string& GetPanelId() const;
        bool IsEnabled() const;

        void SetEnabled(bool enabled);

    protected:
        virtual void DrawImpl() = 0;

        std::string m_panelId = "";
        bool m_enabled = true;

    private:
        static inline uint64_t m_id = 0;
    };
}

#endif // UI_PANELS_BASE_PANEL_HPP_
