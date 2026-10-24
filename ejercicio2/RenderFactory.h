#pragma once

#include <memory>

#include "Button.h"
#include "Shader.h"
#include "Window.h"

class RenderFactory {
public:
    virtual ~RenderFactory() = default;

    virtual std::unique_ptr<Window> createWindow() const = 0;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Shader> createShader() const = 0;
};
