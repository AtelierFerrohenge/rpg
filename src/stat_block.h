#pragma once

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

#include "stat_defs.h"

using namespace godot;

class StatBlock : public Resource {
    GDCLASS(StatBlock, Resource)

public:
    enum ModifierType {
        MODIFIER_TYPE_ADD,
        MODIFIER_TYPE_MULTIPLY,
        MODIFIER_TYPE_OVERRIDE,
    };

    StatBlock() = default;
    ~StatBlock() override = default;

    void set_stat_defs(const Ref<StatDefs> &p_stat_defs);
    Ref<StatDefs> get_stat_defs() const;

    void set_modifier(bool p_modifier);
    bool is_modifier() const;
    void set_modifier_type(ModifierType p_modifier_type);
    ModifierType get_modifier_type() const;
    void set_modifier_priority(int p_modifier_priority);
    int get_modifier_priority() const;

protected:
    static void _bind_methods();
    bool _set(const StringName &p_name, const Variant &p_value);
    bool _get(const StringName &p_name, Variant &r_ret) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

private:
    TypedDictionary<StringName, Variant> stats;

    Ref<StatDefs> stat_defs;

    bool modifier = false;
    ModifierType modifier_type = MODIFIER_TYPE_ADD;
    int modifier_priority = 0;
};

VARIANT_ENUM_CAST(StatBlock::ModifierType);