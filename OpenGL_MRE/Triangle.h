#pragma once
#include <vector>

#include "Entity.h"

class Triangle : public Entity
{
public:
    Triangle(const std::vector<double>& positions, const std::vector<float>& colors);

    void Color() override;
    static void InitShader();

protected:
    ~Triangle() = default;

private:
    static void CompileShaders();
};