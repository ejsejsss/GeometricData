#include "cube.hpp"

Cube::Cube(std::string name)
        : Object3D(name) {
}

double Cube::area() {
    double area_face = Vertex::lenght(this->getVertexes().at(0),
                                      this->getVertexes().at(1));
    return 6 * area_face * area_face;
}

double Cube::volume() {
    double area_face = Vertex::lenght(this->getVertexes().at(0),
                                      this->getVertexes().at(1));
    return area_face * area_face * area_face;
}

std::istream &operator>>(std::istream &in, Cube &cube) {

    Vertex v(0, 0, 0);
    for (int i = 0; i < 8; i++) {
        in >> v;
        cube.addVertex(v);

    }
    return in;
}



