#pragma once

#include <cmath>
#include <iostream>
#include <regex>
#include <cstring>

class Vertex {
private:
    double x;
    double y;
    double z;

public:
    explicit Vertex(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    explicit Vertex();

    inline double getX() const { return this->x; }
    inline double getY() const { return this->y; }
    inline double getZ() const { return this->z; }

    static inline double lenght(const Vertex& v1, const Vertex& v2){
        return pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2);
    }

    
};

