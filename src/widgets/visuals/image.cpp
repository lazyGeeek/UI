#include "ui/widgets/visuals/image.hpp"
#include "ui/utils/converter.hpp"

#include <imgui/imgui.h>

namespace UI::Widgets::Visuals
{
    Image::Image(uint32_t textureId, float width, float height) :
        BaseWidget("Image"),
        m_id { textureId }
    {
        Resize(width, height);
    }

    void Image::DrawImpl()
    {
        ImGui::Image((ImTextureID)(intptr_t)m_id, m_size, ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
    }
}
