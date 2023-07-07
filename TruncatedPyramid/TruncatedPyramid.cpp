
#include "TruncatedPyramid.hpp"

TruncatedPyramid::TruncatedPyramid(std::string name) : Object3D(name) {

}

double TruncatedPyramid::volume() {
    double base1 = _area_base(0);
    double base2 = _area_base(3);
    double height = _height();
    return 1.0 / 3.0 * height * (base1 + base2 + sqrt(base1 * base2));
}

double TruncatedPyramid::area() {
    double base1 = _area_base(0);
    double base2 = _area_base(3);
    double sideArea = 0.0;
    sideArea += _area_side(getVertexes().at(0), getVertexes().at(1), getVertexes().at(3), getVertexes().at(4));
    sideArea += _area_side(getVertexes().at(1), getVertexes().at(2), getVertexes().at(4), getVertexes().at(5));
    sideArea += _area_side(getVertexes().at(0), getVertexes().at(2), getVertexes().at(3), getVertexes().at(5));
    return sideArea + base1 + base2;
}

std::istream &operator>>(std::istream &in, TruncatedPyramid &p) {
    Vertex v(0, 0, 0);
    while (!in.eof()) {
        in >> v;
        p.addVertex(v);
    }
    return in;
}

double TruncatedPyramid::_height() {
    const Vertex &a = getVertexes()[0];
    const Vertex &b = getVertexes()[1];
    const Vertex &c = getVertexes()[2];

    const Vertex &p = getVertexes()[3];

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

double TruncatedPyramid::_area_base(int i) {
    double a, b, c, p;
    a = Vertex::lenght(getVertexes()[i + 0], getVertexes()[i + 1]);
    b = Vertex::lenght(getVertexes()[i + 1], getVertexes()[i + 2]);
    c = Vertex::lenght(getVertexes()[i + 0], getVertexes()[i + 2]);
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double TruncatedPyramid::_area_side(const Vertex &v1, const Vertex &v2, const Vertex &v3, const Vertex &v4) {
    double a, b, c, d, e, p1, p2;
    a = Vertex::lenght(v1,v2);
    b = Vertex::lenght(v2,v3);
    c = Vertex::lenght(v3,v4);
    d = Vertex::lenght(v1,v4);
    e = Vertex::lenght(v1,v3);
    p1 = (d + e + c) / 2;
    p2 = (a + b + e) / 2;
    return sqrt(p1 * (p1 - d) * (p1 - e) * (p1 - c)) + sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - e));
}
