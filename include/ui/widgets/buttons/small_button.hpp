#pragma once
#ifndef UI_WIDGETS_BUTTONS_SMALL_BUTTON_HPP_
#define UI_WIDGETS_BUTTONS_SMALL_BUTTON_HPP_

#include <imgui/imgui.h>

#include "ui/types/color.hpp"
#include "ui/widgets/buttons/base_button.hpp"

namespace UI::Widgets::Buttons
{
    class SmallButton : public BaseButton
    {
    public:
        SmallButton(const std::string& label = "");
        virtual ~SmallButton() = default;

        SmallButton(const SmallButton& other)             = delete;
        SmallButton(SmallButton&& other)                  = delete;
        SmallButton& operator=(const SmallButton& other)  = delete;
        SmallButton& operator=(const SmallButton&& other) = delete;

    protected:
        virtual void DrawImpl() override;
    };
}

#endif // UI_WIDGETS_BUTTONS_SMALL_BUTTON_HPP_
