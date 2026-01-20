#pragma once

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

using StatDefsDictionary = TypedDictionary<StringName, int>;

// Figure out if it's possible to make a change to the script itself trigger notify_property_list_changed()
class StatDefs : public Resource {
    GDCLASS(StatDefs, Resource)

public:
    StatDefs() = default;
    ~StatDefs() override = default;

    // Review if I should use PackedStringArray instead
    TypedArray<StringName> get_stat_names() const;

    virtual StatDefsDictionary get_stat_defs() const;

protected:
    static void _bind_methods();

    // Review if I should return a pointer or reference instead
    GDVIRTUAL0RC_REQUIRED(StatDefsDictionary, _get_stat_defs)
};