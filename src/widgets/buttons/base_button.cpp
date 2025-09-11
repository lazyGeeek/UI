#include "ui/widgets/buttons/base_button.hpp"

namespace UI::Widgets::Buttons
{
    const Types::Color& BaseButton::GetBackgroundColor() const
    {
        return m_backgroundColor;
    }

    const Types::Color& BaseButton::GetHoveredBackgroundColor() const
    {
        return m_hoveredBackgroundColor;
    }

    const Types::Color& BaseButton::GetActiveBackgroundColor() const
    {
        return m_activeBackgroundColor;
    }
    
    const Types::Color& BaseButton::GetTextColor() const
    {
        return m_textColor;
    }

    void BaseButton::SetBackgroundColor(const Types::Color& color)
    {
        m_backgroundColor = color;
    }
    
    void BaseButton::SetHoveredBackgroundColor(const Types::Color& color)
    {
        m_hoveredBackgroundColor = color;
    }
    
    void BaseButton::SetActiveBackgroundColor(const Types::Color& color)
    {
        m_activeBackgroundColor  = color;
    }
    
    void BaseButton::SetTextColor(const Types::Color& color)
    {
        m_textColor = color;
    }
}
