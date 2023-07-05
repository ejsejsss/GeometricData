#pragma once
#include "object3d.hpp"

class Parallelepiped : public Object3D {
public:

    explicit Parallelepiped(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, Parallelepiped &p);
};

