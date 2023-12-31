#pragma once

#include "Entity.h"

class Triangle : public Entity
{
public:
    Triangle(const std::vector<double>& positions, const std::vector<float>& colors);

    void Color() override;
    void CompileShaders() override;

protected:
    ~Triangle() = default;
};
