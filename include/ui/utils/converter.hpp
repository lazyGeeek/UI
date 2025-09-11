#pragma once
#ifndef UI_UTILS_CONVERTER_HPP_
#define UI_UTILS_CONVERTER_HPP_

#include <imgui/imgui.h>

#include "ui/types/color.hpp"

namespace UI::Utils
{
    struct Converter
    {
    public:
        static ImVec4 ToImVec4(const Types::Color& color)
        {
            return ImVec4(color.R, color.G, color.B, color.A);
        }

        static Types::Color ToColor(const ImVec4& imVec2)
        {
            return Types::Color(imVec2.x, imVec2.y, imVec2.z, imVec2.w);
        }
    };
}

#endif // UI_UTILS_CONVERTER_HPP_
