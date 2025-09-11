#pragma once
#ifndef UI_WIDGETS_TEXTS_COLORED_TEXT_HPP_
#define UI_WIDGETS_TEXTS_COLORED_TEXT_HPP_

#include "ui/types/color.hpp"
#include "ui/widgets/texts/text.hpp"

namespace UI::Widgets::Texts
{
    class ColoredText : public Text
    {
    public:
        ColoredText(const Types::Color& color, char const* const format, ...);
        virtual ~ColoredText() override = default;

        ColoredText(const ColoredText& other)             = delete;
        ColoredText(ColoredText&& other)                  = delete;
        ColoredText& operator=(const ColoredText& other)  = delete;
        ColoredText& operator=(const ColoredText&& other) = delete;

        const Types::Color& GetColor() const;
        void SetColor(const Types::Color& color);

    protected:
        virtual void DrawImpl() override;

        Types::Color m_color = Types::Color::White;;
    };
}

#endif // UI_WIDGETS_TEXTS_COLORED_TEXT_HPP_
