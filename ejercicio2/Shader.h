#pragma once

class Shader {
public:
    virtual ~Shader() = default;
    virtual void compile() const = 0;
};
