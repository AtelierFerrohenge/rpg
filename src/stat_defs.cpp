#include "stat_defs.h"

TypedArray<StringName> StatDefs::get_stat_names() const {
    return get_stat_defs().keys();
}

StatDefsDictionary StatDefs::get_stat_defs() const {
    StatDefsDictionary ret;
    GDVIRTUAL_CALL(_get_stat_defs, ret);
    return ret;
}

void StatDefs::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_stat_names"), &StatDefs::get_stat_names);

    GDVIRTUAL_BIND(_get_stat_defs);
}