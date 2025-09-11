#pragma once
#ifndef UI_SETTINGS_GROUP_WIDGET_SETTINGS_HPP_
#define UI_SETTINGS_GROUP_WIDGET_SETTINGS_HPP_

namespace UI::Settings
{
    struct GroupWidgetSettings
    {
        bool Border                 = true;
        bool AlwaysUseWindowPadding = true;
        bool ResizeX                = false;
        bool ResizeY                = false;
        bool AutoResizeX            = false;
        bool AutoResizeY            = false;
        bool FrameStyle             = true;
    };
}

#endif // UI_SETTINGS_GROUP_WIDGET_SETTINGS_HPP_
