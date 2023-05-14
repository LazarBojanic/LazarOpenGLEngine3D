A simple 3D demo scene, with procedural generation, ambient, diffuse, specular lighting, full 3D camera movement, light emitting objects, normal mapping, specular mapping made in OpenGL and C++.

Libraries and DLLs can be found at the following repository: https://github.com/LazarBojanic/LazarOpenGLEngine3D

The project was made in Microsoft Visual Studio 2022 (x64).

Here I am putting an epilepsy warning just in case.

![animated GIF](LazarOpenGLEngine3D-1.gif)

![animated GIF](LazarOpenGLEngine3D-2.gif)

Libraries in use:

GLFW - OpenGL context,
Glad - OpenGL functions,
stbi_image - texture loading,
glm - mathematics library,
irrKlang - sound.

Instructions:
- If you're cloning, copy DLLs from the "dlls" folder in the repository to x64/Debug or x64/Release depending on the desired configuration. Download the "libraries" folder from the repository and place it in the project's root folder next to "assets", "src" etc. Build the project in Visual Studio. Then you can either run it from there, or just run the generated .exe file.
- Else, Download the latest release from releases.

Controls:
- WASD - movement
- Mouse - look around
- F - Wireframe view