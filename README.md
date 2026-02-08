# Build process

To build 3rd party libraries call python script form UI root folder

Example:
```sh
python3 "/thirdparty/build_dependencies.py <params>
```

List of params:
- glfw - to include GLFW library

# Renderer

To use Vulkan specify `cmake -Bbuild . -DUI_USE_VULKAN=ON`
For OpenGL remove `build` and `bin` folders and build with `cmake -Bbuild .` or `cmake -Bbuild . -DWINDOW_USE_VULKAN=OFF`

# Window

To use GLFW specify `cmake -Bbuild . -DUI_USE_GLFW=ON`

