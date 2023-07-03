#pragma once

#include <vector>

#include "vertex.hpp"

class Face {
private:
    std::vector<Vertex> vertexes;

public:
    explicit Face(std::vector<Vertex> vertexes)
    {
        this->setVertexes(vertexes);
    }

    inline std::vector<Vertex> getVertexes() const
    {
        return this->vertexes;
    }

    inline void setVertexes(const std::vector<Vertex> vertexes)
    {
        this->vertexes = vertexes;
    }
};
