#pragma once
#ifndef UI_PANELS_WINDOW_PANEL_HPP_
#define UI_PANELS_WINDOW_PANEL_HPP_

#include "ui/panels/transformable_panel.hpp"
#include "ui/settings/panel_window_settings.hpp"
#include "ui/utils/event.hpp"

namespace UI::Panels
{
    class WindowPanel : public TransformablePanel
    {
    public:
        WindowPanel
        (
            const std::string& name = "",
            bool opened = true,
            const Settings::PanelWindowSettings& windowSettings = Settings::PanelWindowSettings { },
            float x     = 0.0f, float y      = 0.0f,
            float width = 1.0f, float height = 1.0f,
            Settings::EVerticalAlignment defaultVerticalAlignment     = Settings::EVerticalAlignment::Top,
            Settings::EHorizontalAlignment defaultHorizontalAlignment = Settings::EHorizontalAlignment::Left
        );

        virtual ~WindowPanel();

        WindowPanel(const WindowPanel& other)             = delete;
        WindowPanel(WindowPanel&& other)                  = delete;
        WindowPanel& operator=(const WindowPanel& other)  = delete;
        WindowPanel& operator=(const WindowPanel&& other) = delete;

        void Open();
        void Close();
        void Focus();
        void SetOpened(bool value);
        bool IsAppearing() const;

        bool IsOpened()  const;
        bool IsHovered() const;
        bool IsFocused() const;

        void ScrollToBottom();
        void ScrollToTop();
        void ScrollToRight();
        void ScrollToLeft();

        bool IsScrolledToBottom() const;
        bool IsScrolledToTop()    const;
        bool IsScrolledToRight()  const;
        bool IsScrolledToLeft()   const;

        bool IsAutoSize() const;
        void SetAutoSize(bool autoSize);

        bool IsPaddingsDisabled() const;
        void DisablePaddings(bool value);

        UI::Utils::Event<> OpenEvent;
        UI::Utils::Event<> CloseEvent;

    protected:
        void DrawImpl() override;

        std::string m_name = "";

        float m_minWidth  = 0.0f;
        float m_minHeight = 0.0f;
        float m_maxWidth  = 0.0f;
        float m_maxHeight = 0.0f;

        Settings::PanelWindowSettings m_windowSettings;

    private:
        bool m_opened             = true;
        bool m_hovered            = true;
        bool m_focused            = true;
        bool m_scrolledToBottom   = false;
        bool m_scrolledToTop      = false;

        bool m_mustScrollToBottom = false;
        bool m_mustScrollToTop    = false;
        bool m_mustScrollToRight  = false;
        bool m_mustScrollToLeft   = false;

        bool m_disablePaddings    = false;
    };
}

#endif // ENGINE_UI_PANELS_PANEL_WINDOW_HPP_
