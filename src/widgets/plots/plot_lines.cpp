#include "ui/widgets/plots/plot_lines.hpp"
#include "ui/utils/converter.hpp"

namespace UI::Widgets::Plots
{
    PlotLines::PlotLines(const std::string& label,
        const std::string& overlay,
        unsigned samplesToShow,
        float minScale, float maxScale,
        float width, float height) :
        BasePlot(label, overlay, samplesToShow, minScale, maxScale, width, height) { }

    void PlotLines::DrawImpl()
    {
        ImGui::PlotLines((m_label + m_widgetId).c_str(), m_data.data(),
            static_cast<int>(m_data.size()),
            0, m_overlay.c_str(), m_minScale, m_maxScale,
            m_size, sizeof(float));
    }
}
