#pragma once
#ifndef UI_PANELS_MENU_BAR_PANEL_HPP_
#define UI_PANELS_MENU_BAR_PANEL_HPP_

#include "base_panel.hpp"

namespace UI::Panels
{
    class MenuBarPanel : public BasePanel
    {
    public:
        MenuBarPanel()          = default;
        virtual ~MenuBarPanel() = default;

        MenuBarPanel(const MenuBarPanel& other)             = delete;
        MenuBarPanel(MenuBarPanel&& other)                  = delete;
        MenuBarPanel& operator=(const MenuBarPanel& other)  = delete;
        MenuBarPanel& operator=(const MenuBarPanel&& other) = delete;

    protected:
        virtual void DrawImpl() override;
    };
}

#endif // UI_PANELS_MENU_BAR_PANEL_HPP_
