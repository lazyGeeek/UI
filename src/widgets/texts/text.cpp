#include "ui/widgets/texts/text.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Texts
{
    Text::Text(char const* const format, ...) : 
        BaseText(format)
    {
        va_list args;
        va_start(args, format);
        parseArgs(format, args);
        va_end(args);
    }

    void Text::DrawImpl()
    {
        if (!m_enabled)
            return;

        ImGui::Text("%s", m_content.c_str());
    }
}
