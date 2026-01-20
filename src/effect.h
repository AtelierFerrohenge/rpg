#pragma once

#include "godot_cpp/classes/resource.hpp"

#include "stat_modifier.h"

using namespace godot;

class Effect : public Resource {
    GDCLASS(Effect, Resource)

public:
    Effect() = default;
    ~Effect() override = default;

    void set_modifiers(const TypedArray<StatModifier> &p_modifiers);
    TypedArray<StatModifier> get_modifiers() const;

protected:
    static void _bind_methods();

private:
    // Review if this should be LocalVector or other
    Vector<Ref<StatModifier>> modifiers;
};