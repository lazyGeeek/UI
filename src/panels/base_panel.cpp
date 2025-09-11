#include "ui/panels/base_panel.hpp"

namespace UI::Panels
{
    BasePanel::BasePanel()
    {
        m_panelId = "##" + std::to_string(m_id++);
    }

    const std::string& BasePanel::GetPanelId() const
    {
        return m_panelId;
    }
    
    bool BasePanel::IsEnabled() const
    { 
        return m_enabled;
    }

    void BasePanel::SetEnabled(bool enabled)
    {
        m_enabled = enabled;
    }

    bool BasePanel::Draw()
    {
        if (m_enabled)
        {
            DrawImpl();
            return true;
        }

        return false;
    }
}
