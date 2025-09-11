#include "ui/widgets/plots/base_plot.hpp"
#include "ui/utils/converter.hpp"

namespace UI::Widgets::Plots
{
    BasePlot::BasePlot(const std::string& label,
        const std::string& overlay,
        unsigned samplesToShow,
        float minScale, float maxScale,
        float width, float height) :
        BaseWidget(label),
        m_overlay { overlay },
        m_minScale { minScale },
        m_maxScale { maxScale }
    {
        Resize(width, height);
        m_samplesToShow = samplesToShow == 0 ? 1 : samplesToShow;
        m_data = std::vector<float>(m_samplesToShow, 0.0f);
    }

    void BasePlot::SetOverlay(const std::string& overlay)
    {
        m_overlay = overlay;
    }
    
    void BasePlot::SetMinScale(float minScale)
    {
        m_minScale = minScale;
    }
    
    void BasePlot::SetMaxScale(float maxScale)
    {
        m_maxScale = maxScale;
    }

    void BasePlot::SetData(const std::initializer_list<float>& data)
    {
        if (data.size() > m_samplesToShow)
        {
            size_t diff = data.size() - m_samplesToShow;
            m_data.assign(data.begin() + diff, data.end());
            return;
        }

        m_data.assign(data);
    }

    void BasePlot::SetSamplesToShow(unsigned samplesToShow)
    {
        m_samplesToShow = samplesToShow == 0 ? 1 : samplesToShow;
        m_data.resize(m_samplesToShow, 0.0f);
    }

    void BasePlot::AddSample(float sample)
    {
        if (m_data.size() < m_samplesToShow)
        {
            m_data.push_back(sample);
            return;
        }

        std::vector<float> newData(m_data.begin() + 1, m_data.end());
        newData.push_back(sample);
        m_data.swap(newData);
    }

    const std::string& BasePlot::GetOverlay() const
    {
        return m_overlay;
    }
    
    const std::vector<float>& BasePlot::GetData() const
    {
        return m_data;
    }
    
    float BasePlot::GetMinScale() const
    {
        return m_minScale;
    }
    
    float BasePlot::GetMaxScale() const
    {
        return m_maxScale;
    }
    
    unsigned BasePlot::GetSamplesToShowCount() const
    {
        return static_cast<unsigned>(m_data.size());
    }
}
