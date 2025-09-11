#pragma once
#ifndef UI_WIDGETS_INTERFACES_RESIZABLE_HPP_
#define UI_WIDGETS_INTERFACES_RESIZABLE_HPP_

#include <imgui/imgui.h>

#include <tuple>

namespace UI::Widgets::Interfaces
{
    class Resizable
    {
    public:
        virtual void Resize(float width, float height) { m_size = ImVec2(width, height); }
        virtual std::tuple<float, float> GetSize() const { return { m_size.x, m_size.y }; }

    protected:
        ImVec2 m_size = ImVec2(1.0f, 1.0f);
    };
}

#endif // UI_WIDGETS_INTERFACES_RESIZABLE_HPP_
