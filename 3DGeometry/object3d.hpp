#pragma once


#include <string>
#include <vector>

#include "IArea.hpp"
#include "IVolume.hpp"
#include "face.hpp"

class Object3D : IArea, IVolume {
private:
    std::string name;
    std::vector<Face> faces;
    std::vector<Vertex> vertixes;

public:
    explicit Object3D(std::string name, const std::vector<Face> faces)
    {
        setName(name);
        setFaces(faces);
    }

    explicit Object3D(std::string name)
    {
        setName(name);
    }

    inline std::string getName() const
    {
        return this->name;
    }

    inline void setName(const std::string name)
    {
        this->name = name;
    }

    inline const std::vector<Face> getFaces() const
    {
        return this->faces;
    }

    inline void setFaces(const std::vector<Face> faces)
    {
        this->faces = faces;
    }

    inline void addVertex(const Vertex v) {
        this->vertixes.push_back(v);
    }

    inline const std::vector<Vertex> getVertexes() {
        return this->vertixes;
    }
};
