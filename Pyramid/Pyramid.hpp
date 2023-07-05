#pragma once

#include "object3d.hpp"

class Pyramid : public Object3D {
public:
    explicit Pyramid(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, Pyramid &p);

private:
    double _tetrahedronVolume(const Vertex& p1, const Vertex& p2, const Vertex& p3, const Vertex& p4);
};

