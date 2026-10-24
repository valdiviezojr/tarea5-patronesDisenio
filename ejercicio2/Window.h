#pragma once

class Window {
public:
    virtual ~Window() = default;
    virtual void draw() const = 0;
};
