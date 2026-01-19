#pragma once

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

using StatDefsDictionary = TypedDictionary<StringName, int>;

class StatDefs : public Resource {
    GDCLASS(StatDefs, Resource)

public:
    StatDefs() = default;
    ~StatDefs() override = default;

    TypedArray<StringName> get_stat_names() const;

    virtual StatDefsDictionary get_stat_defs() const;

protected:
    static void _bind_methods();

    // Review if I should return a pointer or reference instead
    GDVIRTUAL0RC_REQUIRED(StatDefsDictionary, _get_stat_defs)
};