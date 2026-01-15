#include "stat_block.h"

StatDefDictionary StatBlock::get_stat_defs() const {
    StatDefDictionary ret;
    GDVIRTUAL_CALL(_get_stat_defs, ret);
    return ret;
}

void StatBlock::_bind_methods() {
    GDVIRTUAL_BIND(_get_stat_defs);
}

bool StatBlock::_set(const StringName &p_name, const Variant &p_value) {
    if(get_stat_defs().has(p_name)) {
        stats[p_name] = p_value;
        return true;
    }
    return false;
}

bool StatBlock::_get(const StringName &p_name, Variant &r_ret) const {
    if(get_stat_defs().has(p_name)) {
        // Make sure this is the right way to return a null Variant
        r_ret = stats.get(p_name, Variant());
        return true;
    }
    return false;
}

void StatBlock::_get_property_list(List<PropertyInfo> *p_list) const {
    // Maybe store this in a variable
    StatDefDictionary stat_defs = get_stat_defs();
    for(Variant &E : stat_defs.keys()) {
        p_list->push_back(PropertyInfo(static_cast<Variant::Type>(static_cast<int>(stat_defs[E])), static_cast<StringName>(E)));
    }
}