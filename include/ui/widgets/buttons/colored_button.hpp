#pragma once
#ifndef UI_WIDGETS_BUTTONS_COLORED_BUTTON_HPP_
#define UI_WIDGETS_BUTTONS_COLORED_BUTTON_HPP_

#include <imgui/imgui.h>

#include "ui/types/color.hpp"
#include "ui/widgets/buttons/base_button.hpp"

namespace UI::Widgets::Buttons
{
    class ColoredButton : public BaseButton
    {
    public:
        ColoredButton(const std::string& label = "",
            const Types::Color& color = Types::Color::Black,
            float width = 0.0f, float height = 0.0f,
            bool enableAlpha = true);

        virtual ~ColoredButton() = default;

        ColoredButton(const ColoredButton& other)             = delete;
        ColoredButton(ColoredButton&& other)                  = delete;
        ColoredButton& operator=(const ColoredButton& other)  = delete;
        ColoredButton& operator=(const ColoredButton&& other) = delete;

        const Types::Color& GetColor()     const;
        std::tuple<float, float> GetSize() const;

        bool IsAlphaEnabled() const;

        void SetColor(const Types::Color& color);
        void SetSize(float width, float height);

        void  EnableAlpha(bool enableAlpha);

    protected:
        virtual void DrawImpl() override;

    private:
        const Types::Color& GetBackgroundColor()        const override;
        const Types::Color& GetHoveredBackgroundColor() const override;
        const Types::Color& GetActiveBackgroundColor()  const override;

        void SetBackgroundColor(const Types::Color& color)        override { }
        void SetHoveredBackgroundColor(const Types::Color& color) override { }
        void SetActiveBackgroundColor(const Types::Color& color)  override { }

        Types::Color m_backgroundColor        = Types::Color::Black;
        Types::Color m_hoveredBackgroundColor = Types::Color::Black;
        Types::Color m_activeBackgroundColor  = Types::Color::Black;

        Types::Color m_color  = Types::Color::Black;
        ImVec2 m_size         = ImVec2(0.0f, 0.0f);
        bool m_isAlphaEnabled = true;
    };
}

#endif // UI_WIDGETS_BUTTONS_COLORED_BUTTON_HPP_
