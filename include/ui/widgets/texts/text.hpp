#pragma once
#ifndef UI_WIDGETS_TEXTS_TEXT_HPP_
#define UI_WIDGETS_TEXTS_TEXT_HPP_

#include "ui/widgets/texts/base_text.hpp"

namespace UI::Widgets::Texts
{
    class Text : public BaseText
    {
    public:
        Text(char const* const format, ...);
        virtual ~Text() override = default;

        Text(const Text& other)             = delete;
        Text(Text&& other)                  = delete;
        Text& operator=(const Text& other)  = delete;
        Text& operator=(const Text&& other) = delete;

    protected:
        virtual void DrawImpl() override;

    };
}

#endif // UI_WIDGETS_TEXTS_TEXT_HPP_
