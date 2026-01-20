#include "effect.h"

void Effect::set_modifiers(const TypedArray<StatModifier> &p_modifiers) {
    modifiers.clear();
    // Review if this needs type validation
    for(Variant modifier : p_modifiers) {
        modifiers.push_back(modifier);
    }
}

TypedArray<StatModifier> Effect::get_modifiers() const {
    TypedArray<StatModifier> result;
    for(Ref<StatModifier> modifier : modifiers) {
        result.push_back(modifier);
    }
    return result;
}

void Effect::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_modifiers", "modifiers"), &Effect::set_modifiers);
    ClassDB::bind_method(D_METHOD("get_modifiers"), &Effect::get_modifiers);

    // Figure out if I can use MAKE_RESOURCE_TYPE_HINT
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "modifiers", PROPERTY_HINT_ARRAY_TYPE, "StatModifier"), "set_modifiers", "get_modifiers");
}