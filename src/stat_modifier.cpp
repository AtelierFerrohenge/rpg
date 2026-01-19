#include "stat_modifier.h"

void StatModifier::set_stat_defs(const Ref<StatDefs> &p_stat_defs) {
    stat_defs = p_stat_defs;
    notify_property_list_changed();
}

Ref<StatDefs> StatModifier::get_stat_defs() const {
    return stat_defs;
}

void StatModifier::set_modifier_type(ModifierType p_modifier_type) {
    modifier_type = p_modifier_type;
}

StatModifier::ModifierType StatModifier::get_modifier_type() const {
    return modifier_type;
}

void StatModifier::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_stat_defs", "stat_defs"), &StatModifier::set_stat_defs);
    ClassDB::bind_method(D_METHOD("get_stat_defs"), &StatModifier::get_stat_defs);
    ClassDB::bind_method(D_METHOD("set_modifier_type", "modifier_type"), &StatModifier::set_modifier_type);
    ClassDB::bind_method(D_METHOD("get_modifier_type"), &StatModifier::get_modifier_type);

    // TO DO: Turn stat defs into a target stat enum
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "stat_defs", PROPERTY_HINT_RESOURCE_TYPE, "StatDefs"), "set_stat_defs", "get_stat_defs");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modifier_type", PROPERTY_HINT_ENUM, "Additive,Multiplicative,Overriding"), "set_modifier_type", "get_modifier_type");

    BIND_ENUM_CONSTANT(MODIFIER_TYPE_ADD);
    BIND_ENUM_CONSTANT(MODIFIER_TYPE_MULTIPLY);
    BIND_ENUM_CONSTANT(MODIFIER_TYPE_OVERRIDE);
}