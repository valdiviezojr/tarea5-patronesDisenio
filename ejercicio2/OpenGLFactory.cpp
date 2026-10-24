#include "OpenGLFactory.h"

#include <iostream>

namespace {

class OpenGLWindow final : public Window {
public:
    void draw() const override {
        std::cout << "[OpenGL] Ventana GLFW con contexto OpenGL 4.6 y VAO listo\n";
    }
};

class OpenGLButton final : public Button {
public:
    void draw() const override {
        std::cout << "[OpenGL] Boton dibujado con vertex buffer y shader program GLSL\n";
    }
};

class OpenGLShader final : public Shader {
public:
    void compile() const override {
        std::cout << "[OpenGL] Shader GLSL 4.60 compilado por el driver\n";
    }
};

}

std::unique_ptr<Window> OpenGLFactory::createWindow() const {
    return std::make_unique<OpenGLWindow>();
}

std::unique_ptr<Button> OpenGLFactory::createButton() const {
    return std::make_unique<OpenGLButton>();
}

std::unique_ptr<Shader> OpenGLFactory::createShader() const {
    return std::make_unique<OpenGLShader>();
}
