
#include "Prism.hpp"

Prism::Prism(std::string name) : Object3D(name) {

}

double Prism::volume() {
    return _height()*_area_base();
}

double Prism::area() {

    double p = 0.0;
    for(auto i = 0; i < getVertexes().size()/2 - 1; i++) {
        p += Vertex::lenght(getVertexes().at(i), getVertexes().at(i + 1));
    }
    p += Vertex::lenght(getVertexes().at(0), getVertexes().at(getVertexes().size()/2-1));

    return _height()*p;
}

std::istream &operator>>(std::istream &in, Prism &p) {
    Vertex v(0, 0, 0);
    for (int i = 0; i < 8; i++) {
        in >> v;
        p.addVertex(v);
    }
    return in;
}

double Prism::_height() {
    const Vertex &a = getVertexes()[0];
    const Vertex &b = getVertexes()[1];
    const Vertex &c = getVertexes()[2];

    const Vertex &p = getVertexes().back();

    double abX = b.getX() - a.getX();
    double abY = b.getY() - a.getY();
    double abZ = b.getZ() - a.getZ();

    double acX = c.getX() - a.getX();
    double acY = c.getY() - a.getY();
    double acZ = c.getZ() - a.getZ();

    double normalX = abY * acZ - abZ * acY;
    double normalY = abZ * acX - abX * acZ;
    double normalZ = abX * acY - abY * acX;

    double d = -normalX * a.getX() - normalY * a.getY() - normalZ * a.getZ();

    double h = std::abs(normalX * p.getX() + normalY * p.getY() + normalZ * p.getZ() + d) /
               std::sqrt(normalX * normalX + normalY * normalY + normalZ * normalZ);
    return h;
}

double Prism::_area_base() {
    double area;
    double p, a, b, c;
    for (auto i = 2; i < getVertexes().size()/2 - 1; i++) {
        a = Vertex::lenght(getVertexes().at(0), getVertexes().at(i - 1));
        b = Vertex::lenght(getVertexes().at(i - 1), getVertexes().at(i));
        c = Vertex::lenght(getVertexes().at(i), getVertexes().at(0));
        p = (a + b + c) / 2;
        area += sqrt(p * (p - a) * (p - b) * (p - c));
    }
    a = Vertex::lenght(getVertexes().at(0), getVertexes().at(getVertexes().size()/2 - 1));
    b = Vertex::lenght(getVertexes().at(getVertexes().size()/2 - 2), getVertexes().at(getVertexes().size()/2 - 1));
    c = Vertex::lenght(getVertexes().at(getVertexes().size()/2 - 2), getVertexes().at(0));
    p = (a + b + c) / 2;
    area += sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}
