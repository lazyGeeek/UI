#include "ui/widgets/buttons/button.hpp"
#include "ui/utils/converter.hpp"

namespace UI::Widgets::Buttons
{
    Button::Button(const std::string& label, float width, float height) :
        BaseButton(label), m_size { ImVec2(width, height) }
    {
        ImGuiStyle& style = ImGui::GetStyle();

        m_backgroundColor        = Utils::Converter::ToColor(style.Colors[ImGuiCol_Button]);
        m_hoveredBackgroundColor = Utils::Converter::ToColor(style.Colors[ImGuiCol_ButtonHovered]);
        m_activeBackgroundColor  = Utils::Converter::ToColor(style.Colors[ImGuiCol_ButtonActive]);
        m_textColor              = Utils::Converter::ToColor(style.Colors[ImGuiCol_Text]);
    }

    std::tuple<float, float> Button::GetSize() const
    {
        return { m_size.y, m_size.y };
    }

    void Button::SetSize(float width, float height)
    {
        m_size = ImVec2(width, height);
    }

    void Button::DrawImpl()
    {
        if (!m_enabled)
            return;

        ImGuiStyle& style = ImGui::GetStyle();

        ImVec4 defaultColor        = style.Colors[ImGuiCol_Button];
        ImVec4 defaultHoveredColor = style.Colors[ImGuiCol_ButtonHovered];
        ImVec4 defaultActiveColor  = style.Colors[ImGuiCol_ButtonActive];
        ImVec4 defaultTextColor    = style.Colors[ImGuiCol_Text];

        style.Colors[ImGuiCol_Button]        = Utils::Converter::ToImVec4(m_backgroundColor);
        style.Colors[ImGuiCol_ButtonHovered] = Utils::Converter::ToImVec4(m_hoveredBackgroundColor);
        style.Colors[ImGuiCol_ButtonActive]  = Utils::Converter::ToImVec4(m_activeBackgroundColor);
        style.Colors[ImGuiCol_Text]          = Utils::Converter::ToImVec4(m_textColor);

        if (ImGui::Button((m_label + m_widgetId).c_str(), m_size))
            ClickedEvent.Invoke();

        style.Colors[ImGuiCol_Button]        = defaultColor;
        style.Colors[ImGuiCol_ButtonHovered] = defaultHoveredColor;
        style.Colors[ImGuiCol_ButtonActive]  = defaultActiveColor;
        style.Colors[ImGuiCol_Text]          = defaultTextColor;
    }
}
