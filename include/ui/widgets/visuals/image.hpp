#pragma once
#ifndef UI_WIDGETS_VISUALS_IMAGE_HPP_
#define UI_WIDGETS_VISUALS_IMAGE_HPP_

#include "ui/widgets/base_widget.hpp"
#include "ui/widgets/interfaces/resizable.hpp"

namespace UI::Widgets::Visuals
{
    class Image : public BaseWidget, public Interfaces::Resizable
    {
    public:
        Image(uint32_t textureId, float width, float height);
        virtual ~Image() override = default;

        Image(const Image& other)             = delete;
        Image(Image&& other)                  = delete;
        Image& operator=(const Image& other)  = delete;
        Image& operator=(const Image&& other) = delete;

    protected:
        virtual void DrawImpl() override;

    private:
        uint32_t m_id = 0;
    };
}

#endif // UI_WIDGETS_VISUALS_IMAGE_HPP_
