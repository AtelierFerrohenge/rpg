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

void StatModifier::set_target_stat(int p_target_stat) {
    target_stat = p_target_stat;
    notify_property_list_changed();
}

int StatModifier::get_target_stat() const {
    return target_stat;
}

void StatModifier::set_modifier_value(Variant p_modifier_value) {
    modifier_value = p_modifier_value;
}

Variant StatModifier::get_modifier_value() const {
    return modifier_value;
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

bool StatModifier::_set(const StringName &p_name, const Variant &p_value) {
    if(stat_defs.is_valid()) {
        // Check if I can use SNAME("suit") somehow
        // Potentially turn this into a switch
        if(p_name == StringName("target_stat")) {
            set_target_stat(p_value);
        } else if(p_name == StringName("modifier_value")) {
            set_modifier_value(p_value);
        } else {
            return false;
        }
        return true;
    }
    
    return false;
}

bool StatModifier::_get(const StringName &p_name, Variant &r_ret) const {
    if(stat_defs.is_valid()) {
        // Check if I can use SNAME("suit") somehow
        // Potentially turn this into a switch
        if(p_name == StringName("target_stat")) {
            r_ret = get_target_stat();
        } else if(p_name == StringName("modifier_value")) {
            r_ret = get_modifier_value();
        } else {
            return false;
        }
        return true;
    }

    return false;
}

void StatModifier::_get_property_list(List<PropertyInfo> *p_list) const {
    if(stat_defs.is_valid()) {
        // Check if I can use PNAME("suit") somehow
        // Review if a bunch of push_backs is the right way to do this
        p_list->push_back(PropertyInfo(Variant::INT, "target_stat", PROPERTY_HINT_ENUM, get_stat_names_enum_hint()));
        p_list->push_back(PropertyInfo(static_cast<Variant::Type>(get_stat_type()), "modifier_value"));
    }
}

String StatModifier::get_stat_names_enum_hint() const {
    if(stat_defs.is_null()) {
        return "";
    }

    return String(",").join(stat_defs->get_stat_names());
}

int StatModifier::get_stat_type() const {
    if(stat_defs.is_null()) {
        return Variant::NIL;
    }

    // Optimize this and perhaps move this into a private variable or relevant setter
    StringName stat_name = stat_defs->get_stat_names()[target_stat];
    return stat_defs->get_stat_defs()[stat_name];
}