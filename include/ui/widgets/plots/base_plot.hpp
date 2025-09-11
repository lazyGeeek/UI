#pragma once
#ifndef UI_WIDGETS_PLOTS_BASE_PLOT_HPP_
#define UI_WIDGETS_PLOTS_BASE_PLOT_HPP_

#include "ui/widgets/base_widget.hpp"
#include "ui/widgets/interfaces/resizable.hpp"

#include <imgui/imgui.h>

#include <limits>
#include <vector>

namespace UI::Widgets::Plots
{
    class BasePlot : public BaseWidget, public Interfaces::Resizable
    {
    public:
        BasePlot(const std::string& label,
            const std::string& overlay = "",
            unsigned samplesToShow = 50,
            float minScale = std::numeric_limits<float>::min(),
            float maxScale = std::numeric_limits<float>::max(),
            float width = 0.0f, float height = 0.0f);

        virtual ~BasePlot() = default;

        BasePlot(const BasePlot& other)             = delete;
        BasePlot(BasePlot&& other)                  = delete;
        BasePlot& operator=(const BasePlot& other)  = delete;
        BasePlot& operator=(const BasePlot&& other) = delete;

        virtual void SetOverlay(const std::string& overlay);
        virtual void SetMinScale(float minScale);
        virtual void SetMaxScale(float maxScale);

        virtual void SetData(const std::initializer_list<float>& data);
        virtual void SetSamplesToShow(unsigned samplesToShow);
        virtual void AddSample(float sample);

        virtual const std::string& GetOverlay()     const;
        virtual const std::vector<float>& GetData() const;
        virtual float GetMinScale()                 const;
        virtual float GetMaxScale()                 const;
        virtual unsigned GetSamplesToShowCount()    const;

    protected:
        virtual void DrawImpl() override = 0;

        std::string m_overlay     = "";
        std::vector<float> m_data = std::vector<float>();
        unsigned m_samplesToShow  = 50;
        float m_minScale          = std::numeric_limits<float>::min();
        float m_maxScale          = std::numeric_limits<float>::max();
    };
}

#endif // UI_WIDGETS_PLOTS_BASE_PLOT_HPP_
