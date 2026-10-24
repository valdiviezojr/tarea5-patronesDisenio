#include <iostream>
#include <memory>

#include "OpenGLFactory.h"
#include "RenderFactory.h"
#include "VulkanFactory.h"

namespace {

void renderScene(const RenderFactory& factory) {
    auto window = factory.createWindow();
    auto button = factory.createButton();
    auto shader = factory.createShader();

    window->draw();
    button->draw();
    shader->compile();
}

}

int main() {
    std::cout << "=== Ejercicio 2: Abstract Factory RenderFactory ===\n";

    std::unique_ptr<RenderFactory> factory = std::make_unique<OpenGLFactory>();
    std::cout << "-- OpenGLFactory --\n";
    renderScene(*factory);

    factory = std::make_unique<VulkanFactory>();
    std::cout << "-- VulkanFactory (fabrica cambiada en tiempo de ejecucion) --\n";
    renderScene(*factory);

    return 0;
}
