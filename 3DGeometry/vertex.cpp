#include <regex>
#include "vertex.hpp"

Vertex::Vertex() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

std::istream &operator>>(std::istream &in, Vertex &vertex) {
    std::string ss;
    in >> ss;
    const char *delim = ";";
    char *str = const_cast<char *>(ss.c_str());
    vertex.x = strtod(strtok(str, ";"), nullptr);
    vertex.y = strtod(strtok(NULL, ";"), nullptr);
    vertex.z = strtod(strtok(NULL, ";"), nullptr);

    return in;
}

std::ostream &operator<<(std::ostream &out, const Vertex &vertex) {
    return out << vertex.x << ';' << vertex.y << ';' << vertex.z ;
}


