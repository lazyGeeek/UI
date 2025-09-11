#pragma once
#ifndef UI_WIDGETS_TEXTS_TEXT_FILTER_HPP_
#define UI_WIDGETS_TEXTS_TEXT_FILTER_HPP_

#include "ui/widgets/base_widget.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Texts
{
    class TextFilter : public BaseWidget
    {
    public:
        TextFilter(const std::string& label = "");
        virtual ~TextFilter() override = default;

        TextFilter(const TextFilter& other)             = delete;
        TextFilter(TextFilter&& other)                  = delete;
        TextFilter& operator=(const TextFilter& other)  = delete;
        TextFilter& operator=(const TextFilter&& other) = delete;

        virtual bool PassFilter(const std::string& line);

        virtual std::string GetFilterText();

    protected:
        virtual void DrawImpl() override;

        ImGuiTextFilter m_filter;

    };
}

#endif // UI_WIDGETS_TEXTS_TEXT_FILTER_HPP_
