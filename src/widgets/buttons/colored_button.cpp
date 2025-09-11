#include "ui/widgets/buttons/colored_button.hpp"
#include "ui/utils/converter.hpp"

namespace UI::Widgets::Buttons
{
    ColoredButton::ColoredButton(const std::string& label, const Types::Color& color,
        float width, float height, bool enableAlpha) :
        BaseButton(label),
          m_color { color },
          m_size { ImVec2(width, height) },
          m_isAlphaEnabled { enableAlpha }
    {
        ImGuiStyle& style = ImGui::GetStyle();

        m_textColor = Utils::Converter::ToColor(style.Colors[ImGuiCol_Text]);
    }

    const Types::Color& ColoredButton::GetColor() const
    {
        return m_color;
    }
    
    std::tuple<float, float> ColoredButton::GetSize() const
    {
        return { m_size.y, m_size.y };
    }

    bool ColoredButton::IsAlphaEnabled() const
    {
        return m_isAlphaEnabled;
    }

    void ColoredButton::SetColor(const Types::Color& color)
    {
        m_color = color;
    }
    
    void ColoredButton::SetSize(float width, float height)
    {
        m_size  = ImVec2(width, height);
    }

    void ColoredButton::EnableAlpha(bool enableAlpha)
    {
        m_isAlphaEnabled = enableAlpha;
    }

    void ColoredButton::DrawImpl()
    {
        if (!m_enabled)
            return;

        ImGuiStyle& style = ImGui::GetStyle();

        ImVec4 defaultTextColor = style.Colors[ImGuiCol_Text];

        style.Colors[ImGuiCol_Text] = Utils::Converter::ToImVec4(m_textColor);

        if (ImGui::ColorButton((m_label + m_widgetId).c_str(), Utils::Converter::ToImVec4(m_color),
            !m_isAlphaEnabled ? ImGuiColorEditFlags_NoAlpha : 0, m_size))
            ClickedEvent.Invoke();

        style.Colors[ImGuiCol_Text] = defaultTextColor;
    }

    const Types::Color& ColoredButton::GetBackgroundColor() const
    {
        return m_backgroundColor;
    }
    
    const Types::Color& ColoredButton::GetHoveredBackgroundColor() const
    {
        return m_hoveredBackgroundColor;
    }
    
    const Types::Color& ColoredButton::GetActiveBackgroundColor() const
    {
        return m_activeBackgroundColor;
    }
}
