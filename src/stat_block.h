#pragma once

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;
using StatDefDictionary = TypedDictionary<StringName, int>;

class StatBlock : public Resource {
    GDCLASS(StatBlock, Resource)

public:
    StatBlock() = default;
    ~StatBlock() override = default;

    StatDefDictionary get_stat_defs() const;

protected:
    static void _bind_methods();
    bool _set(const StringName &p_name, const Variant &p_value);
    bool _get(const StringName &p_name, Variant &r_ret) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

    // Review if I should return a pointer or reference instead
    GDVIRTUAL0RC_REQUIRED(StatDefDictionary, _get_stat_defs)

private:
    TypedDictionary<StringName, Variant> stats;
};
