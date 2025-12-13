# Add checks for whether children are actually item.gd instances once Item has more features
class_name EquipmentSet
extends Node

@export var _cap: int = 0


func check_capped() -> bool:
	return get_child_count() >= _cap
