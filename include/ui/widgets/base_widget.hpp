#pragma once
#ifndef UI_WIDGETS_BASE_WIDGET_HPP_
#define UI_WIDGETS_BASE_WIDGET_HPP_

#include <memory>
#include <string>

#include "ui/drawable_interface.hpp"
#include "ui/widgets/widget_container.hpp"

namespace UI::Widgets
{
    class BaseWidget : public IDrawable
    {
    public:
        BaseWidget(const std::string& label);
        virtual ~BaseWidget() = default;

        BaseWidget(const BaseWidget& other)             = delete;
        BaseWidget(BaseWidget&& other)                  = delete;
        BaseWidget& operator=(const BaseWidget& other)  = delete;
        BaseWidget& operator=(const BaseWidget&& other) = delete;

        virtual bool Draw() override;
        virtual void Destroy();

        virtual bool IsDestroyed() const;

        virtual bool HasParent() const;
        virtual WidgetContainer* GetParent();

        virtual const std::string& GetWidgetId() const;
        virtual const std::string& GetLabel()    const;

        virtual void SetLabel(const std::string& text);

        virtual void SetEnabled(bool enabled);
        virtual void SetSameLine(bool sameLine);
        virtual void Separate(bool separated);

        virtual bool IsEnabled()   const;
        virtual bool IsSameLine()  const;
        virtual bool IsSeparated() const;

    protected:
        virtual void DrawImpl() = 0;

        WidgetContainer* m_parent = nullptr;

        std::string m_widgetId = "";
        std::string m_label    = "";

        bool m_enabled   = true;
        bool m_sameLine  = false;
        bool m_separated = false;

    private:
        friend void WidgetContainer::AddWidget(std::shared_ptr<BaseWidget> widget, bool manageMemory);
        friend void WidgetContainer::RemoveWidget(std::shared_ptr<BaseWidget> widget);
        friend void WidgetContainer::RemoveAllWidgets();

        static inline uint64_t m_id = 0;
        bool m_destroyed = false;
    };
}

#endif // UI_WIDGETS_BASE_WIDGET_HPP_
