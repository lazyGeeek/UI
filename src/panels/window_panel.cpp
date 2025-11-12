#include "ui/panels/window_panel.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include "ui/widgets/buttons/button.hpp"

namespace UI::Panels
{
    WindowPanel::WindowPanel(const std::string& name, bool opened,
        const Settings::PanelWindowSettings& windowSettings,
        float x, float y, float width, float height,
        Settings::EVerticalAlignment defaultVerticalAlignment,
        Settings::EHorizontalAlignment defaultHorizontalAlignment) :
        TransformablePanel(x, y, width, height, defaultVerticalAlignment, defaultHorizontalAlignment),
        m_name { name },
        m_opened { opened },
        m_windowSettings { windowSettings }
    {
        m_autoSize = windowSettings.AutoSize;
    }

    WindowPanel::~WindowPanel()
    {
        RemoveAllWidgets();
    }

    void WindowPanel::Open()
    {
        if (m_opened)
            return;

        m_opened = true;
        OpenEvent.Invoke();
    }

    void WindowPanel::Close()
    {
        if (!m_opened)
            return;

        m_opened = false;
        CloseEvent.Invoke();
    }

    void WindowPanel::Focus()
    {
        ImGui::SetWindowFocus((m_name + m_panelId).c_str());
    }

    void WindowPanel::SetOpened(bool value)
    {
        if (value == m_opened)
            return;

        m_opened = value;

        if (m_opened)
            OpenEvent.Invoke();
        else
            CloseEvent.Invoke();
    }

    bool WindowPanel::IsAppearing() const
    {
        if (ImGuiWindow* window = ImGui::FindWindowByName((m_name + GetPanelId()).c_str()); window)
            return window->Appearing;
        else
            return false;
    }

    bool WindowPanel::IsOpened() const
    {
        return m_opened;
    }
    
    bool WindowPanel::IsHovered() const
    {
        return m_hovered;
    }

    bool WindowPanel::IsFocused() const
    {
        return m_focused;
    }

    void WindowPanel::ScrollToBottom()
    {
        m_mustScrollToBottom = true;
    }
    
    void WindowPanel::ScrollToTop()
    {
        m_mustScrollToTop = true;
    }
    
    void WindowPanel::ScrollToRight()
    {
        m_mustScrollToRight = true;
    }
    
    void WindowPanel::ScrollToLeft()
    {
        m_mustScrollToLeft = true;
    }

    bool WindowPanel::IsScrolledToBottom() const
    {
        return m_mustScrollToBottom;
    }
    
    bool WindowPanel::IsScrolledToTop() const
    {
        return m_mustScrollToTop;
    }
    
    bool WindowPanel::IsScrolledToRight() const
    {
        return m_mustScrollToRight;
    }
    
    bool WindowPanel::IsScrolledToLeft() const
    {
        return m_mustScrollToLeft;
    }

    bool WindowPanel::IsAutoSize() const
    {
        return m_autoSize;
    }
    
    void WindowPanel::SetAutoSize(bool autoSize)
    {
        m_autoSize = autoSize;
    }

    bool WindowPanel::IsPaddingsDisabled() const
    {
        return m_disablePaddings;
    }
    
    void WindowPanel::DisablePaddings(bool value)
    {
        m_disablePaddings = value;
    }

    void WindowPanel::DrawImpl()
    {
        if (!m_opened)
            return;

        int windowFlags = ImGuiWindowFlags_None;

        if (!m_windowSettings.Resizable)               windowFlags |= ImGuiWindowFlags_NoResize;
        if (!m_windowSettings.Movable)                 windowFlags |= ImGuiWindowFlags_NoMove;
        if (!m_windowSettings.Dockable)                windowFlags |= ImGuiWindowFlags_NoDocking;
        if (m_windowSettings.HideBackground)           windowFlags |= ImGuiWindowFlags_NoBackground;
        if (m_windowSettings.ForceHorizontalScrollbar) windowFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        if (m_windowSettings.ForceVerticalScrollbar)   windowFlags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
        if (m_windowSettings.AllowHorizontalScrollbar) windowFlags |= ImGuiWindowFlags_HorizontalScrollbar;
        if (!m_windowSettings.BringToFrontOnFocus)     windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        if (!m_windowSettings.Collapsable)             windowFlags |= ImGuiWindowFlags_NoCollapse;
        if (!m_windowSettings.AllowInputs)             windowFlags |= ImGuiWindowFlags_NoInputs;
        if (!m_windowSettings.Scrollable)              windowFlags |= ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar;
        if (!m_windowSettings.TitleBar)                windowFlags |= ImGuiWindowFlags_NoTitleBar;
        if (m_autoSize)                                windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

        ImVec2 minSizeConstraint(m_minWidth, m_minHeight);
        ImVec2 maxSizeConstraint(m_maxWidth, m_maxHeight);

        if (minSizeConstraint.x <= 0.0f || minSizeConstraint.y <= 0.0f)
            minSizeConstraint = { 0.0f, 0.0f };

        if (maxSizeConstraint.x <= 0.0f || maxSizeConstraint.y <= 0.0f)
            maxSizeConstraint = { 100000.0f, 100000.0f };

        ImGui::SetNextWindowSizeConstraints(minSizeConstraint, maxSizeConstraint);

        if (m_disablePaddings)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

        if (ImGui::Begin((m_name + m_panelId).c_str(), m_windowSettings.Closable ? &m_opened : nullptr, windowFlags))
        {
            m_hovered = ImGui::IsWindowHovered();
            m_focused = ImGui::IsWindowFocused();

            float scrollY = ImGui::GetScrollY();

            m_scrolledToBottom = scrollY == ImGui::GetScrollMaxY();
            m_scrolledToTop = scrollY == 0.0f;

            if (!m_opened)
                CloseEvent.Invoke();

            Update();

            if (m_mustScrollToBottom)
            {
                ImGui::SetScrollY(ImGui::GetScrollMaxY());
                m_mustScrollToBottom = false;
            }

            if (m_mustScrollToTop)
            {
                ImGui::SetScrollY(0.0f);
                m_mustScrollToTop = false;
            }

            if (m_mustScrollToRight)
            {
                ImGui::SetScrollX(ImGui::GetScrollMaxX());
                m_mustScrollToRight = false;
            }

            if (m_mustScrollToLeft)
            {
                ImGui::SetScrollX(0.0f);
                m_mustScrollToLeft = false;
            }

            DrawWidgets();
        }

        ImGui::End();

        if (m_disablePaddings)
            ImGui::PopStyleVar();
    }
}
