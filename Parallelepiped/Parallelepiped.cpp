#include "Parallelepiped.hpp"

Parallelepiped::Parallelepiped(std::string name) : Object3D(name) {

}

double Parallelepiped::volume() {
    double a = Vertex::lenght(this->getVertexes().at(0),
                              this->getVertexes().at(1));
    double b = Vertex::lenght(this->getVertexes().at(1),
                              this->getVertexes().at(2));
    double h = Vertex::lenght(this->getVertexes().at(1),
                              this->getVertexes().at(5));
    return a*b*h;
}

double Parallelepiped::area() {
    double a = Vertex::lenght(this->getVertexes().at(0),
                               this->getVertexes().at(1));
    double b = Vertex::lenght(this->getVertexes().at(1),
                               this->getVertexes().at(2));
    double h = Vertex::lenght(this->getVertexes().at(1),
                              this->getVertexes().at(5));
    return 2 * (a*b + b*h + a*h);
}

std::istream &operator>>(std::istream &in, Parallelepiped &p) {
    Vertex v(0, 0, 0);
    for (int i = 0; i < 8; i++) {
        in >> v;
        p.addVertex(v);
    }
    return in;
}
