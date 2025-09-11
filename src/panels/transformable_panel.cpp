#include "ui/panels/transformable_panel.hpp"

#include <imgui/imgui.h>

namespace UI::Panels
{
    TransformablePanel::TransformablePanel
    (
        float x, float y, float width, float height,
        Settings::EVerticalAlignment defaultVerticalAlignment,
        Settings::EHorizontalAlignment defaultHorizontalAlignment,
        bool ignoreConfigFile) :
        m_defaultVerticalAlignment   { defaultVerticalAlignment },
        m_defaultHorizontalAlignment { defaultHorizontalAlignment },
        m_ignoreConfigFile           { ignoreConfigFile }
    {
        Resize(width, height);
        SetPosition(x, y);
        SetVerticalAlignment(m_defaultVerticalAlignment);
        SetHorizontalAlignment(m_defaultHorizontalAlignment);
    }

    void TransformablePanel::SetPosition(float x, float y)
    {
        m_x = x;
        m_y = y;
        m_positionChanged = true;
    }

    void TransformablePanel::SetHorizontalAlignment(Settings::EHorizontalAlignment horizontalAlignment)
    {
        m_horizontalAlignment = horizontalAlignment;
        m_alignmentChanged = true;
    }

    void TransformablePanel::SetVerticalAlignment(Settings::EVerticalAlignment verticalAligment)
    {
        m_verticalAlignment = verticalAligment;
        m_alignmentChanged = true;
    }

    void TransformablePanel::Resize(float width, float height)
    {
        m_width = width;
        m_height = height;
        m_sizeChanged = true;
    }

    std::tuple<float, float> TransformablePanel::GetContentSize() const
    {
        return { m_contentWidth, m_contentHeight };
    }

    std::tuple<float, float> TransformablePanel::GetPosition() const
    {
        return { m_x, m_y };
    }

    Settings::EHorizontalAlignment TransformablePanel::GetHorizontalAlignment() const
    {
        return m_horizontalAlignment;
    }
    
    Settings::EVerticalAlignment TransformablePanel::GetVerticalAlignment() const
    {
        return m_verticalAlignment;
    }

    void TransformablePanel::updatePosition()
    {
        if (m_positionChanged || m_alignmentChanged)
        {
            auto [offsetX, offsetY] = calculatePositionAlignmentOffset(false);
            ImGui::SetWindowPos(ImVec2(m_x + offsetX, m_y + offsetY), ImGuiCond_Always);
            m_positionChanged = false;
            m_alignmentChanged = false;
        }
    }

    void TransformablePanel::updateSize()
    {
        if (m_sizeChanged)
        {
            ImGui::SetWindowSize(ImVec2(m_width, m_height), ImGuiCond_Always);
            m_sizeChanged = false;
        }
    }

    void TransformablePanel::copyImGuiSize()
    {
        ImVec2 size = ImGui::GetWindowSize();
        m_width = size.x;
        m_height = size.y;

        size = ImGui::GetContentRegionAvail();
        m_contentWidth = size.x;
        m_contentHeight = size.y;
    }

    void TransformablePanel::copyImGuiPosition()
    {
        ImVec2 pos = ImGui::GetWindowPos();
        m_x = pos.x;
        m_y = pos.y;
    }

    void TransformablePanel::Update()
    {
        if (!m_firstFrame)
        {
            if (!m_autoSize)
                updateSize();
            copyImGuiSize();

            updatePosition();
            copyImGuiPosition();
        }

        m_firstFrame = false;
    }

    std::tuple<float, float> TransformablePanel::calculatePositionAlignmentOffset(bool useDefault)
    {
        float offsetX = 0.0f;
        float offsetY = 0.0f;

        switch (useDefault ? m_defaultHorizontalAlignment : m_horizontalAlignment)
        {
            case Settings::EHorizontalAlignment::Middle:
            {
                offsetX -= m_width / 2.0f;
                break;
            }
            case Settings::EHorizontalAlignment::Right:
            {
                offsetX -= m_width;
                break;
            }
            case Settings::EHorizontalAlignment::Left:
            {
                break;
            }
        }

        switch (useDefault ? m_defaultVerticalAlignment : m_verticalAlignment)
        {
            case Settings::EVerticalAlignment::Middle:
            {
                offsetY -= m_height / 2.0f;
                break;
            }
            case Settings::EVerticalAlignment::Bottom:
            {
                offsetY -= m_height;
                break;
            }
            case Settings::EVerticalAlignment::Top:
            {
                break;
            }
        }

        return { offsetX, offsetY };
    }
}
