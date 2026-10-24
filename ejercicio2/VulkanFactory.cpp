#include "VulkanFactory.h"

#include <iostream>

namespace {

class VulkanWindow final : public Window {
public:
    void draw() const override {
        std::cout << "[Vulkan] Ventana con surface y swapchain sobre dispositivo Vulkan\n";
    }
};

class VulkanButton final : public Button {
public:
    void draw() const override {
        std::cout << "[Vulkan] Boton dibujado mediante command buffer y pipeline\n";
    }
};

class VulkanShader final : public Shader {
public:
    void compile() const override {
        std::cout << "[Vulkan] Shader SPIR-V validado y cargado como VkShaderModule\n";
    }
};

}

std::unique_ptr<Window> VulkanFactory::createWindow() const {
    return std::make_unique<VulkanWindow>();
}

std::unique_ptr<Button> VulkanFactory::createButton() const {
    return std::make_unique<VulkanButton>();
}

std::unique_ptr<Shader> VulkanFactory::createShader() const {
    return std::make_unique<VulkanShader>();
}
