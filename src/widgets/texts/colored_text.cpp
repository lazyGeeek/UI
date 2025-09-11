#include "ui/widgets/texts/colored_text.hpp"
#include "ui/utils/converter.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Texts
{
    ColoredText::ColoredText(const Types::Color& color, char const* const format, ...) :
        Text(format), m_color { color }
    {
        va_list args;
        va_start(args, format);
        parseArgs(format, args);
        va_end(args);
    }

    const Types::Color& ColoredText::GetColor() const
    {
        return m_color;
    }
    
    void ColoredText::SetColor(const Types::Color& color)
    {
        m_color = color;
    }

    void ColoredText::DrawImpl()
    {
        if (!m_enabled)
            return;

        ImGui::TextColored(Utils::Converter::ToImVec4(m_color), "%s", m_content.c_str());
    }
}
