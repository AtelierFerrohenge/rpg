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
    // TO DO: Turn stat defs into a target stat enum
    void set_modifier_type(ModifierType p_modifier_type);
    ModifierType get_modifier_type() const;

protected:
    static void _bind_methods();

private:
    Ref<StatDefs> stat_defs;
    ModifierType modifier_type = MODIFIER_TYPE_ADD;
};

VARIANT_ENUM_CAST(StatModifier::ModifierType);