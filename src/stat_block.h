#pragma once

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

#include "stat_defs.h"

using namespace godot;

class StatBlock : public Resource {
    GDCLASS(StatBlock, Resource)

public:
    StatBlock() = default;
    ~StatBlock() override = default;

    void set_stat_defs(const Ref<StatDefs> &p_stat_defs);
    Ref<StatDefs> get_stat_defs() const;

protected:
    static void _bind_methods();
    bool _set(const StringName &p_name, const Variant &p_value);
    bool _get(const StringName &p_name, Variant &r_ret) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

private:
    Ref<StatDefs> stat_defs;
    TypedDictionary<StringName, Variant> stats;
};