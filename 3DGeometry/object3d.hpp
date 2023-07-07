#pragma once


#include <string>
#include <vector>

#include "IArea.hpp"
#include "IVolume.hpp"
#include "vertex.hpp"

class Object3D : public IArea, public IVolume {
private:
    std::string name;
    std::vector<Vertex> vertixes;

public:

    explicit Object3D(std::string name) {
        setName(name);
    }

    inline std::string getName() const {
        return this->name;
    }

    inline void setName(const std::string name) {
        this->name = name;
    }

    inline void addVertex(const Vertex v) {
        this->vertixes.push_back(v);
    }

    inline const std::vector<Vertex>& getVertexes() {
        return this->vertixes;
    }
};
