#pragma once
#ifndef UI_PANELS_TRANSFORMABLE_PANEL_HPP_
#define UI_PANELS_TRANSFORMABLE_PANEL_HPP_

#include "base_panel.hpp"
#include "ui/settings/alignment.hpp"
#include "ui/widgets/interfaces/resizable.hpp"

namespace UI::Panels
{
    class TransformablePanel : public BasePanel, public Widgets::Interfaces::Resizable
    {
    public:
        TransformablePanel
        (
            float x     = 0.0f, float y      = 0.0f,
            float width = 1.0f, float height = 1.0f,
            Settings::EVerticalAlignment defaultVerticalAlignment     = Settings::EVerticalAlignment::Top,
            Settings::EHorizontalAlignment defaultHorizontalAlignment = Settings::EHorizontalAlignment::Left,
            bool ignoreConfigFile = false
        );

        virtual ~TransformablePanel() { }

        TransformablePanel(const TransformablePanel& other)             = delete;
        TransformablePanel(TransformablePanel&& other)                  = delete;
        TransformablePanel& operator=(const TransformablePanel& other)  = delete;
        TransformablePanel& operator=(const TransformablePanel&& other) = delete;

        virtual void SetPosition(float x, float y);
        virtual void Resize(float width, float height) override;
        virtual std::tuple<float, float> GetContentSize() const;

        virtual void SetHorizontalAlignment(Settings::EHorizontalAlignment horizontalAlignment);
        virtual void SetVerticalAlignment(Settings::EVerticalAlignment verticalAligment);

        virtual std::tuple<float, float> GetPosition() const;

        Settings::EHorizontalAlignment GetHorizontalAlignment() const;
        Settings::EVerticalAlignment GetVerticalAlignment()     const;

    protected:
        virtual void Update();
        virtual void DrawImpl() override = 0;

        Settings::EHorizontalAlignment m_defaultHorizontalAlignment = Settings::EHorizontalAlignment::Left;
        Settings::EVerticalAlignment m_defaultVerticalAlignment     = Settings::EVerticalAlignment::Top;

        bool m_ignoreConfigFile = true;

        float m_x = 0.0f;
        float m_y = 0.0f;

        float m_width  = 1.0f;
        float m_height = 1.0f;

        float m_contentWidth  = 1.0f;
        float m_contentHeight = 1.0f;

        bool m_positionChanged  = false;
        bool m_sizeChanged      = false;
        bool m_alignmentChanged = false;

        Settings::EHorizontalAlignment m_horizontalAlignment = Settings::EHorizontalAlignment::Left;
        Settings::EVerticalAlignment m_verticalAlignment     = Settings::EVerticalAlignment::Top;

        bool m_firstFrame = true;
        bool m_autoSize   = true;

    private:
        std::tuple<float, float> calculatePositionAlignmentOffset(bool useDefault = false);

        void updatePosition();
        void updateSize();
        void copyImGuiPosition();
        void copyImGuiSize();
    };
}

#endif // UI_PANELS_TRANSFORMABLE_PANEL_HPP_
