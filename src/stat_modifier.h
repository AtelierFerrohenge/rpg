#pragma once

#include "godot_cpp/classes/resource.hpp"

#include "stat_defs.h"

using namespace godot;

class StatModifier : public Resource {
    GDCLASS(StatModifier, Resource)

public:
    enum ModifierType {
        MODIFIER_TYPE_ADD,
        MODIFIER_TYPE_MULTIPLY,
        MODIFIER_TYPE_OVERRIDE,
    };

    StatModifier() = default;
    ~StatModifier() override = default;

    void set_stat_defs(const Ref<StatDefs> &p_stat_defs);
    Ref<StatDefs> get_stat_defs() const;
    void set_modifier_type(ModifierType p_modifier_type);
    ModifierType get_modifier_type() const;
    
    void set_target_stat(int p_target_stat);
    int get_target_stat() const;
    void set_modifier_value(Variant p_modifier_value);
    Variant get_modifier_value() const;

protected:
    static void _bind_methods();

    bool _set(const StringName &p_name, const Variant &p_value);
    bool _get(const StringName &p_name, Variant &r_ret) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

private:
    // Probably don't need the "modifier_" prefix
    Ref<StatDefs> stat_defs;
    ModifierType modifier_type = MODIFIER_TYPE_ADD;
    int target_stat = 0;
    Variant modifier_value;

    String get_stat_names_enum_hint() const;
    int get_stat_type() const;
};

VARIANT_ENUM_CAST(StatModifier::ModifierType);