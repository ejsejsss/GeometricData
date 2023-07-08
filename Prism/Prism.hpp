#pragma once

#include "object3d.hpp"

class Prism : public Object3D {
public:
    explicit Prism(std::string name);

    double volume() override;

    double area() override;

    friend std::istream &operator>>(std::istream &in, Prism &p);
private:
    double _height();
    double _area_base();

};
