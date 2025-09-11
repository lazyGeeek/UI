#pragma once
#ifndef UI_WIDGETS_PLOTS_PLOT_LINES_HPP_
#define UI_WIDGETS_PLOTS_PLOT_LINES_HPP_

#include <vector>

#include <imgui/imgui.h>

#include "ui/widgets/plots/base_plot.hpp"

namespace UI::Widgets::Plots
{
    class PlotLines : public BasePlot
    {
    public:
        PlotLines(const std::string& label,
            const std::string& overlay = "",
            unsigned samplesToShow = 50,
            float minScale = std::numeric_limits<float>::min(),
            float maxScale = std::numeric_limits<float>::max(),
            float width = 0.0f, float height = 0.0f);

        virtual ~PlotLines() = default;

        PlotLines(const PlotLines& other)             = delete;
        PlotLines(PlotLines&& other)                  = delete;
        PlotLines& operator=(const PlotLines& other)  = delete;
        PlotLines& operator=(const PlotLines&& other) = delete;

    protected:
        virtual void DrawImpl() override;
    };
}

#endif // UI_WIDGETS_PLOTS_PLOT_LINES_HPP_
