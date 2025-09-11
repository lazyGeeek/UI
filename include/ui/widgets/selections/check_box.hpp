#pragma once
#ifndef UI_WIDGETS_SELECTIONS_CHECK_BOX_HPP_
#define UI_WIDGETS_SELECTIONS_CHECK_BOX_HPP_

#include "ui/widgets/base_widget.hpp"
#include "ui/utils/event.hpp"

namespace UI::Widgets::Selections
{
    class CheckBox : public BaseWidget
    {
    public:
        CheckBox(const std::string& label, bool value = false);
        virtual ~CheckBox() = default;

        CheckBox(const CheckBox& other)             = delete;
        CheckBox(CheckBox&& other)                  = delete;
        CheckBox& operator=(const CheckBox& other)  = delete;
        CheckBox& operator=(const CheckBox&& other) = delete;

        bool GetValue() const;
        void SetValue(bool value);

        UI::Utils::Event<bool> ValueChangedEvent;

    protected:
        virtual void DrawImpl() override;

        bool m_value = false;
    };
}

#endif // UI_WIDGETS_SELECTIONS_CHECK_BOX_HPP_
