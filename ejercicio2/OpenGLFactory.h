#pragma once

#include "RenderFactory.h"

class OpenGLFactory final : public RenderFactory {
public:
    std::unique_ptr<Window> createWindow() const override;
    std::unique_ptr<Button> createButton() const override;
    std::unique_ptr<Shader> createShader() const override;
};
