#pragma once
#ifndef UI_SETTINGS_PANEL_WINDOW_SETTINGS_HPP_
#define UI_SETTINGS_PANEL_WINDOW_SETTINGS_HPP_

namespace UI::Settings
{
    struct PanelWindowSettings
    {
        bool Closable                 = true;
        bool Resizable                = true;
        bool Movable                  = true;
        bool Dockable                 = true;
        bool Scrollable               = true;
        bool HideBackground           = false;
        bool ForceHorizontalScrollbar = false;
        bool ForceVerticalScrollbar   = false;
        bool AllowHorizontalScrollbar = true;
        bool BringToFrontOnFocus      = true;
        bool Collapsable              = true;
        bool AllowInputs              = true;
        bool TitleBar                 = true;
        bool AutoSize                 = false;
    };
}

#endif // UI_SETTINGS_PANEL_WINDOW_SETTINGS_HPP_
