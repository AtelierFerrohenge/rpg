#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class StatBlock : public Resource {
    GDCLASS(StatBlock, Resource)

public:
    StatBlock() = default;
    ~StatBlock() override = default;

protected:
    static void _bind_methods();
};
