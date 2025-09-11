#pragma once
#ifndef UI_WIDGETS_LAYOUTS_TREE_NODES_HPP_
#define UI_WIDGETS_LAYOUTS_TREE_NODES_HPP_

#include "ui/utils/event.hpp"
#include "ui/widgets/base_widget.hpp"
#include "ui/widgets/widget_container.hpp"

namespace UI::Widgets::Layouts
{
    class TreeNode : public BaseWidget, public WidgetContainer
    {
    public:
        TreeNode(const std::string& label, bool arrowClickToOpen = false);
        virtual ~TreeNode() override;

        TreeNode(const TreeNode& other)             = delete;
        TreeNode(TreeNode&& other)                  = delete;
        TreeNode& operator=(const TreeNode& other)  = delete;
        TreeNode& operator=(const TreeNode&& other) = delete;

        void Open();
        void Close();

        bool IsOpened() const;

        void SetSelected(bool selected);
        void SetAsLeaf(bool isLeaf);

        bool IsSelected() const;
        bool IsLeaf() const;

        UI::Utils::Event<> ClickedEvent;
        UI::Utils::Event<> DoubleClickedEvent;
        UI::Utils::Event<> OpenedEvent;
        UI::Utils::Event<> ClosedEvent;

    protected:
        virtual void DrawImpl() override;

        bool m_selected = false;
        bool m_isLeaf   = false;

    private:
        bool m_arrowClickToOpen = false;
        bool m_shouldOpen       = false;
        bool m_shouldClose      = false;
        bool m_opened           = false;

    };
}

#endif // UI_WIDGETS_LAYOUTS_TREE_NODES_HPP_
