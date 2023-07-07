#pragma once

#include "object3d.hpp"

class Pyramid : public Object3D {
public:
    explicit Pyramid(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, Pyramid &p);

};

