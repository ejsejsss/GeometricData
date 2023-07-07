#pragma once

#include "object3d.hpp"

class TruncatedPyramid: public Object3D {
public:
    explicit TruncatedPyramid(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, TruncatedPyramid &p);
private:
    double _height();
    double _area_base(int i);
    static double _area_side(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4);
};

