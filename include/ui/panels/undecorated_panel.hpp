#pragma once
#ifndef UI_PANELS_UNDECORATED_PANEL_HPP_
#define UI_PANELS_UNDECORATED_PANEL_HPP_

#include "transformable_panel.hpp"

namespace UI::Panels
{
    class UndecoratedPanel : public TransformablePanel
    {
    public:
        UndecoratedPanel()          = default;
        virtual ~UndecoratedPanel() = default;

        UndecoratedPanel(const UndecoratedPanel& other)             = delete;
        UndecoratedPanel(UndecoratedPanel&& other)                  = delete;
        UndecoratedPanel& operator=(const UndecoratedPanel& other)  = delete;
        UndecoratedPanel& operator=(const UndecoratedPanel&& other) = delete;

    protected:
        virtual void DrawImpl() override;

    private:
        int collectFlags();
    };
}

#endif // UI_PANELS_UNDECORATED_PANEL_HPP_
