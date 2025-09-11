#pragma once
#ifndef UI_WIDGETS_BUTTONS_ARROW_BUTTON_HPP_
#define UI_WIDGETS_BUTTONS_ARROW_BUTTON_HPP_

#include <imgui/imgui.h>

#include "ui/types/color.hpp"
#include "ui/widgets/buttons/base_button.hpp"

namespace UI::Widgets::Buttons
{
    class ArrowButton : public BaseButton
    {
    public:
        enum class EDirection
        {
            Left  = 0,
            Right = 1,
            Up    = 2,
            Down  = 3
        };

        ArrowButton(EDirection direction = EDirection::Left);
        virtual ~ArrowButton() = default;

        ArrowButton(const ArrowButton& other)             = delete;
        ArrowButton(ArrowButton&& other)                  = delete;
        ArrowButton& operator=(const ArrowButton& other)  = delete;
        ArrowButton& operator=(const ArrowButton&& other) = delete;

        EDirection GetDirection();

        void SetDirection(EDirection direction);

    protected:
        virtual void DrawImpl() override;

        EDirection fromImGuiDir(ImGuiDir direction);
        ImGuiDir fromEDirection(EDirection direction);

    private:
        ImGuiDir m_direction = ImGuiDir_Left;
    };
}

#endif // UI_WIDGETS_BUTTONS_ARROW_BUTTON_HPP_
