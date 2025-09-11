#include "ui/widgets/visuals/image.hpp"
#include "ui/utils/converter.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Visuals
{
    Image::Image(uint32_t textureId) :
        BaseWidget("Image"), m_textureId { textureId } { }

    void Image::DrawImpl()
    {
        ImGui::Image(m_textureId.raw, m_size, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
    }
}
