#pragma  once

#include "object3d.hpp"
#include <iostream>

class Cube : public Object3D {
public:

    explicit Cube(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, Cube &cube);
};

