#include "stat_block.h"

StatDefDictionary StatBlock::get_stat_defs() const {
    StatDefDictionary ret;
    GDVIRTUAL_CALL(_get_stat_defs, ret);
    return ret;
}

void StatBlock::_bind_methods() {
}

bool StatBlock::_set(const StringName &p_name, const Variant &p_value) {
}

bool StatBlock::_get(const StringName &p_name, Variant &r_ret) const {

}

void StatBlock::_get_property_list(List<PropertyInfo> *p_list) const {
    // For each
}