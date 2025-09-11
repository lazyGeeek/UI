#pragma once
#ifndef UI_WIDGETS_TEXTS_BASE_TEXT_HPP_
#define UI_WIDGETS_TEXTS_BASE_TEXT_HPP_

#include "ui/widgets/base_widget.hpp"

namespace UI::Widgets::Texts
{
    class BaseText : public BaseWidget
    {
    public:
        BaseText(char const* const format, ...);
        virtual ~BaseText() override = default;

        BaseText(const BaseText& other)             = delete;
        BaseText(BaseText&& other)                  = delete;
        BaseText& operator=(const BaseText& other)  = delete;
        BaseText& operator=(const BaseText&& other) = delete;

        virtual const std::string& GetContent() const;
        virtual void SetContent(char const* const format, ...);

    protected:
        virtual void DrawImpl() override = 0;
        void parseArgs(char const* const format, va_list& args);

        std::string m_content = "";

    };
}

#endif // UI_WIDGETS_TEXTS_BASE_TEXT_HPP_
