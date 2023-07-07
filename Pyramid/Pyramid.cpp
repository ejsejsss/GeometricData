#include "Pyramid.hpp"

Pyramid::Pyramid(std::string name) : Object3D(name) {

}

double Pyramid::volume() {
    return (1.0 / 6.0) * std::abs(
            (getVertexes().at(0).getX() - getVertexes().at(3).getX()) *
            ((getVertexes().at(1).getY() - getVertexes().at(3).getY()) *
             (getVertexes().at(2).getZ() - getVertexes().at(3).getZ()) -
             (getVertexes().at(1).getZ() - getVertexes().at(3).getZ()) *
             (getVertexes().at(2).getY() - getVertexes().at(3).getY())) +
            (getVertexes().at(0).getY() - getVertexes().at(3).getY()) *
            ((getVertexes().at(1).getZ() - getVertexes().at(3).getZ()) *
             (getVertexes().at(2).getX() - getVertexes().at(3).getX()) -
             (getVertexes().at(1).getX() - getVertexes().at(3).getX()) *
             (getVertexes().at(2).getZ() - getVertexes().at(3).getZ())) +
            (getVertexes().at(0).getZ() - getVertexes().at(3).getZ()) *
            ((getVertexes().at(1).getX() - getVertexes().at(3).getX()) *
             (getVertexes().at(2).getY() - getVertexes().at(3).getY()) -
             (getVertexes().at(1).getY() - getVertexes().at(3).getY()) *
             (getVertexes().at(2).getX() - getVertexes().at(3).getX()))
    );
}

double Pyramid::area() {
    double area;
    double p, a, b, c;
    for (auto i = 2; i < this->getVertexes().size() - 1; i++) {
        a = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().at(i - 1));
        b = Vertex::lenght(this->getVertexes().at(i - 1), this->getVertexes().at(i));
        c = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().at(0));
        p = (a + b + c) / 2;
        area += sqrt(p * (p - a) * (p - b) * (p - c));
    }

    for (auto i = 0; i < this->getVertexes().size() - 2; i++) {
        a = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().at(i + 1));
        b = Vertex::lenght(this->getVertexes().at(i + 1), this->getVertexes().back());
        c = Vertex::lenght(this->getVertexes().at(i), this->getVertexes().back());
        p = (a + b + c) / 2;
        area += sqrt(p * (p - a) * (p - b) * (p - c));
    }
    a = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().rbegin()[1]);
    b = Vertex::lenght(this->getVertexes().rbegin()[1], this->getVertexes().back());
    c = Vertex::lenght(this->getVertexes().at(0), this->getVertexes().back());
    p = (a + b + c) / 2;
    area += sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}

std::istream &operator>>(std::istream &in, Pyramid &p) {
    Vertex v(0, 0, 0);
    while (!in.eof()) {
        in >> v;
        p.addVertex(v);
    }
    if (p.getVertexes().size() != 4) throw std::string("Колличество вершин не равно 4");
    return in;
}
