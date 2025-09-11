#include "ui/widgets/texts/text_filter.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Texts
{
    TextFilter::TextFilter(const std::string& label) :
        BaseWidget(label) { }

    bool TextFilter::PassFilter(const std::string& line)
    {
        return m_filter.PassFilter(line.c_str());
    }

    std::string TextFilter::GetFilterText()
    {
        return std::string(m_filter.InputBuf);
    }

    void TextFilter::DrawImpl()
    {
        if (m_label.empty())
            m_filter.Draw();
        else
            m_filter.Draw(m_label.c_str());
    }
}
