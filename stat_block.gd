@abstract
class_name StatBlock
extends Resource

enum Type {
	NONE,
	ADD,
	MULTIPLY,
}

@export var type: Type = Type.NONE
@export var priority: int = -1


func modify_with(modifier: StatBlock) -> StatBlock:
	var result: StatBlock = duplicate(true)
	result._apply_modifier(modifier)
	return result


@abstract func _get_stat_properties() -> Array[StringName]


func _apply_modifier(modifier: StatBlock) -> void:
	# Review and optimize
	# Typedef or guard property
	for property in _get_stat_properties():
		match modifier.type:
			Type.ADD:
				set(property, get(property) + modifier.get(property))
			Type.MULTIPLY:
				set(property, get(property) * modifier.get(property))
			_:
				pass # Handle this
