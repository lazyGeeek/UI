set(UI_PROJECT "UI")

if(UI_REBUILD_THIRDPARTY)
    execute_process(COMMAND python3 "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/build_dependencies.py")
endif()

file(
    GLOB_RECURSE UI_BINS_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/bins/*.*"
)

file(
    GLOB_RECURSE UI_LIBS_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libs/*.*"
)

foreach (BIN_FILE ${UI_BINS_LIST})
    file(COPY ${BIN_FILE} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach ()

foreach (LIB_FILE ${UI_LIBS_LIST})
    file(COPY ${LIB_FILE} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach ()

file(
    GLOB_RECURSE UI_CODE_LIST
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ui/*.h*"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ui/*.inl"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_opengl3.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_opengl3.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_glfw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_glfw.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_draw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_internal.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_widgets.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_tables.cpp"
)

add_library(${UI_PROJECT} SHARED ${UI_CODE_LIST})

target_compile_features(${UI_PROJECT} PRIVATE cxx_std_17)
target_include_directories(${UI_PROJECT} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui
)
target_link_libraries(${UI_PROJECT} ${UI_BINS_LIST})

foreach(CODE_FILE IN ITEMS ${UI_CODE_LIST})
    get_filename_component(CODE_FILE_PATH "${CODE_FILE}" PATH)
    file(RELATIVE_PATH CODE_FILE_RELATIVE_PATH "${CMAKE_SOURCE_DIR}" "${CODE_FILE_PATH}")
    string(REPLACE "\\" "/" GROUP_PATH "${CODE_FILE_RELATIVE_PATH}")
    file(RELATIVE_PATH EXTERNAL_INCLUDE_RELATIVE_PATH "${CMAKE_SOURCE_DIR}" "${EXTERNAL_INCLUDE_DIR}/")
    string(REPLACE ${EXTERNAL_INCLUDE_RELATIVE_PATH} "" GROUP_PATH "${GROUP_PATH}")
    string(REPLACE "src" "" GROUP_PATH "${GROUP_PATH}")
    string(REPLACE "include/ui" "" GROUP_PATH "${GROUP_PATH}")
    source_group("${GROUP_PATH}" FILES "${CODE_FILE}")
endforeach()
