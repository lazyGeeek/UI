#pragma once
#ifndef UI_DRAWABLE_INTERFACE_HPP_
#define UI_DRAWABLE_INTERFACE_HPP_

namespace UI
{
    class IDrawable
    {
    public:
        virtual ~IDrawable() = default;
        virtual bool Draw() = 0;
    };
}

#endif // UI_DRAWABLE_INTERFACE_HPP_
