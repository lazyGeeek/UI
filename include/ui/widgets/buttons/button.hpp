#pragma once
#ifndef UI_WIDGETS_BUTTONS_BUTTON_HPP_
#define UI_WIDGETS_BUTTONS_BUTTON_HPP_

#include <imgui/imgui.h>

#include "ui/widgets/buttons/base_button.hpp"

#include <string>
#include <tuple>

namespace UI::Widgets::Buttons
{
    class Button : public BaseButton
    {
    public:
        Button(const std::string& label = "", float width = 0.0f, float height = 0.0f);
        virtual ~Button() = default;

        Button(const Button& other)             = delete;
        Button(Button&& other)                  = delete;
        Button& operator=(const Button& other)  = delete;
        Button& operator=(const Button&& other) = delete;

        std::tuple<float, float> GetSize() const;

        void SetSize(float width, float height);

    protected:
        virtual void DrawImpl() override;

        ImVec2 m_size = ImVec2(0.0f, 0.0f);
    };
}

#endif // UI_WIDGETS_BUTTONS_BUTTON_HPP_
