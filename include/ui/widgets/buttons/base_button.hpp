#pragma once
#ifndef UI_WIDGETS_BUTTONS_BASE_BUTTON_HPP_
#define UI_WIDGETS_BUTTONS_BASE_BUTTON_HPP_

#include "ui/utils/event.hpp"
#include "ui/types/color.hpp"
#include "ui/widgets/base_widget.hpp"

namespace UI::Widgets::Buttons
{
    class BaseButton : public BaseWidget
    {
    public:
        BaseButton(const std::string& label) : BaseWidget(label) { }

        virtual ~BaseButton() = default;

        BaseButton(const BaseButton& other)             = delete;
        BaseButton(BaseButton&& other)                  = delete;
        BaseButton& operator=(const BaseButton& other)  = delete;
        BaseButton& operator=(const BaseButton&& other) = delete;

        virtual const Types::Color& GetBackgroundColor() const;
        virtual const Types::Color& GetHoveredBackgroundColor() const;
        virtual const Types::Color& GetActiveBackgroundColor() const;
        virtual const Types::Color& GetTextColor() const;

        virtual void SetBackgroundColor(const Types::Color& color);
        virtual void SetHoveredBackgroundColor(const Types::Color& color);
        virtual void SetActiveBackgroundColor(const Types::Color& color);
        virtual void SetTextColor(const Types::Color& color);

        UI::Utils::Event<> ClickedEvent;

    protected:
        virtual void DrawImpl() override = 0;

        Types::Color m_backgroundColor        = Types::Color::Black;
        Types::Color m_hoveredBackgroundColor = Types::Color::Black;
        Types::Color m_activeBackgroundColor  = Types::Color::Black;
        Types::Color m_textColor              = Types::Color::Black;
    };
}

#endif // UI_WIDGETS_BUTTONS_BASE_BUTTON_HPP_
