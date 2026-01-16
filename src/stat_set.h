#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class StatSet : public Resource {
    GDCLASS(StatSet, Resource)

public:
    StatSet() = default;
    ~StatSet() override = default;

protected:
    static void _bind_methods();
};