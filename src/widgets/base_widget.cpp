#include "ui/widgets/base_widget.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets
{
    BaseWidget::BaseWidget(const std::string& label) :
        m_label { label }
    {
        m_widgetId = "##" + std::to_string(m_id++);
    }

    bool BaseWidget::Draw()
    {
        if (m_enabled)
        {
            DrawImpl();

            if (m_sameLine)
                ImGui::SameLine();

            return true;
        }

        return false;
    }

    void BaseWidget::Destroy()
    {
        m_destroyed = true;
    }

    bool BaseWidget::IsDestroyed() const
    {
        return m_destroyed;
    }

    bool BaseWidget::HasParent() const
    {
        return m_parent;
    }
    
    WidgetContainer* BaseWidget::GetParent()
    {
        return m_parent;
    }

    const std::string& BaseWidget::GetWidgetId() const
    {
        return m_widgetId;
    }
    
    const std::string& BaseWidget::GetLabel() const
    {
        return m_label;
    }

    void BaseWidget::SetLabel(const std::string& text)
    {
        m_label = text;
    }

    void BaseWidget::SetEnabled(bool enabled)
    {
        m_enabled = enabled;
    }
    
    void BaseWidget::SetSameLine(bool sameLine)
    {
        m_sameLine = sameLine;
    }

    bool BaseWidget::IsEnabled() const
    {
        return m_enabled;
    }
    
    bool BaseWidget::IsSameLine() const
    {
        return m_sameLine;
    }
}
