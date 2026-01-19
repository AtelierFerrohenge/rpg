#include "stat_block.h"

void StatBlock::set_stat_defs(const Ref<StatDefs> &p_stat_defs) {
    stat_defs = p_stat_defs;
    notify_property_list_changed();
}

Ref<StatDefs> StatBlock::get_stat_defs() const {
    return stat_defs;
}

void StatBlock::set_modifier(bool p_modifier) {
    modifier = p_modifier;
}

bool StatBlock::is_modifier() const {
    return modifier;
}

void StatBlock::set_modifier_type(ModifierType p_modifier_type) {
    modifier_type = p_modifier_type;
}

StatBlock::ModifierType StatBlock::get_modifier_type() const {
    return modifier_type;
}

void StatBlock::set_modifier_priority(int p_modifier_priority) {
    modifier_priority = p_modifier_priority;
}

int StatBlock::get_modifier_priority() const {
    return modifier_priority;
}

void StatBlock::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_stat_defs", "stat_defs"), &StatBlock::set_stat_defs);
    ClassDB::bind_method(D_METHOD("get_stat_defs"), &StatBlock::get_stat_defs);

    ClassDB::bind_method(D_METHOD("set_modifier", "modifier"), &StatBlock::set_modifier);
    ClassDB::bind_method(D_METHOD("is_modifier"), &StatBlock::is_modifier);
    ClassDB::bind_method(D_METHOD("set_modifier_type", "modifier_type"), &StatBlock::set_modifier_type);
    ClassDB::bind_method(D_METHOD("get_modifier_type"), &StatBlock::get_modifier_type);
    ClassDB::bind_method(D_METHOD("set_modifier_priority", "modifier_priority"), &StatBlock::set_modifier_priority);
    ClassDB::bind_method(D_METHOD("get_modifier_priority"), &StatBlock::get_modifier_priority);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "stat_defs", PROPERTY_HINT_RESOURCE_TYPE, "StatDefs"), "set_stat_defs", "get_stat_defs");

    ADD_GROUP("Modifier", "modifier_");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "modifier", PROPERTY_HINT_GROUP_ENABLE), "set_modifier", "is_modifier");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modifier_type", PROPERTY_HINT_ENUM, "Additive,Multiplicative,Overriding"), "set_modifier_type", "get_modifier_type");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modifier_priority"), "set_modifier_priority", "get_modifier_priority");
    
    BIND_ENUM_CONSTANT(MODIFIER_TYPE_ADD);
    BIND_ENUM_CONSTANT(MODIFIER_TYPE_MULTIPLY);
    BIND_ENUM_CONSTANT(MODIFIER_TYPE_OVERRIDE);
}

bool StatBlock::_set(const StringName &p_name, const Variant &p_value) {
    if(stat_defs.is_null()) {
        return false;
    }

    if(stat_defs->get_stat_defs().has(p_name)) {
        stats[p_name] = p_value;
        return true;
    }
    return false;
}

bool StatBlock::_get(const StringName &p_name, Variant &r_ret) const {
    if(stat_defs.is_null()) {
        return false;
    }

    if(stat_defs->get_stat_defs().has(p_name)) {
        // Make sure this is the right way to return a null Variant
        r_ret = stats.get(p_name, Variant());
        return true;
    }
    return false;
}

void StatBlock::_get_property_list(List<PropertyInfo> *p_list) const {
    if(stat_defs.is_null()) {
        return;
    }

    // Maybe store this in a variable
    StatDefsDictionary stat_defs_dict = stat_defs->get_stat_defs();
    for(Variant &E : stat_defs_dict.keys()) {
        p_list->push_back(PropertyInfo(static_cast<Variant::Type>(static_cast<int>(stat_defs_dict[E])), static_cast<StringName>(E)));
    }
}