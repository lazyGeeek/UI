#pragma once
#ifndef UI_MODULES_CANVAS_HPP_
#define UI_MODULES_CANVAS_HPP_

#include <memory>
#include <list>

#include "ui/drawable_interface.hpp"
#include "ui/panels/window_panel.hpp"

namespace UI::Panels { class BasePanel; }

namespace UI::Modules
{
    class Canvas : public IDrawable
    {
    public:
        Canvas() = default;
        virtual ~Canvas() override;

        Canvas(const Canvas& other)             = delete;
        Canvas(Canvas&& other)                  = delete;
        Canvas& operator=(const Canvas& other)  = delete;
        Canvas& operator=(const Canvas&& other) = delete;

        template<typename T, typename... Args>
        std::shared_ptr<T> AddPanel(Args&&... args)
        {
            static_assert(std::is_base_of<Panels::BasePanel, T>::value, "T should derive from BasePanel");

            std::shared_ptr<T> instance = std::make_shared<T>(args...);
            m_panels.emplace_back(instance);
            return instance;
        }

        void RemovePanel(std::shared_ptr<Panels::BasePanel> panel);
        void RemoveAllPanels();
        bool Draw() override;

        void SetDockspace(bool state);
        bool IsDockspace() const;

    private:
        std::list<std::shared_ptr<Panels::BasePanel>> m_panels;
        bool m_isDockspace = false;
    };
}

#endif // UI_MODULES_CANVAS_HPP_
