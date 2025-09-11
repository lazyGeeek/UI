#include "ui/widgets/texts/base_text.hpp"

#include <cstdarg>

namespace UI::Widgets::Texts
{    BaseText::BaseText(char const* const format, ...) : BaseWidget("text")
    {
        va_list args;
        va_start(args, format);
        parseArgs(format, args);
        va_end(args);
    }

    const std::string& BaseText::GetContent() const
    {
        return m_content;
    }
    
    void BaseText::SetContent(char const* const format, ...)
    {
        va_list args;
        va_start(args, format);
        parseArgs(format, args);
        va_end(args);
    }

    void BaseText::parseArgs(char const* const format, va_list& args)
    {
        va_list copy;
        va_copy(copy, args);

        int size = vsnprintf(nullptr, 0, format, copy);
        
        if (size <= 0)
        {
            va_end(copy);
            m_content = "";
            return;
        }
        
        m_content = std::string(size + 1, '\0');
        vsnprintf(&m_content[0], size + 1, format, args);
        
        va_end(copy);
    }
}
