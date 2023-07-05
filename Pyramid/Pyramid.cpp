#include "Pyramid.hpp"

Pyramid::Pyramid(std::string name) : Object3D(name) {

}

double Pyramid::volume() {
    Vertex origin = getVertexes().at(0);
    double volume = 0;

    for(auto i = 1; i< getVertexes().size()-2; ++i) {
        volume += _tetrahedronVolume(origin, getVertexes().at(i), getVertexes().at(i+1), getVertexes().at(i+2));
    }
    return std::abs(volume);
}

double Pyramid::area() {
    double area;
    double p, a, b, c;
    for (auto i = 2; i < this->getVertexes().size()-1; i++) {
        a = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().at(i - 1));
        b = Vertex::lenght(this->getVertexes().at(i - 1), this->getVertexes().at(i));
        c = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().at(0));
        p = (a + b + c) / 2;
        area += sqrt(p*(p-a)*(p-b)*(p-c));
    }

    for(auto i = 0; i < this->getVertexes().size() - 2; i++) {
        a = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().at(i + 1));
        b = Vertex::lenght(this->getVertexes().at(i + 1), this->getVertexes().back());
        c = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().back());
        p = (a + b + c) / 2;
        area += sqrt(p*(p-a)*(p-b)*(p-c));
    }
    a = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().rbegin()[1]);
    b = Vertex::lenght(this->getVertexes().rbegin()[1], this->getVertexes().back());
    c = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().back());
    p = (a + b + c) / 2;
    area += sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}

std::istream &operator>>(std::istream &in, Pyramid &p) {
    Vertex v(0, 0, 0);
    while (!in.eof()) {
        in >> v;
        p.addVertex(v);
    }
    return in;
}

double Pyramid::_tetrahedronVolume(const Vertex &p1, const Vertex &p2, const Vertex &p3, const Vertex &p4) {
    double v321 = p3.getX() * p2.getY() * p1.getZ();
    double v231 = p2.getX() * p3.getY() * p1.getZ();
    double v312 = p3.getX() * p1.getY() * p2.getZ();
    double v132 = p1.getX() * p3.getY() * p2.getZ();
    double v213 = p2.getX() * p1.getY() * p3.getZ();
    double v123 = p1.getX() * p2.getY() * p3.getZ();

    double v432 = p4.getX() * p3.getY() * p2.getZ();
    double v342 = p3.getX() * p4.getY() * p2.getZ();
    double v324 = p3.getX() * p2.getY() * p4.getZ();
    double v234 = p2.getX() * p3.getY() * p4.getZ();
    double v423 = p4.getX() * p2.getY() * p3.getZ();
    double v243 = p2.getX() * p4.getY() * p3.getZ();

    return (v321 - v231 + v312 - v132 - v213 + v123 + v432 - v342 + v324 - v234 - v423 + v243)/6.0;
}
