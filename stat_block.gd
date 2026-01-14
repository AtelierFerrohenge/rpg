@abstract
class_name StatBlockOld
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


@abstract func _get_stat_names() -> Array[StringName]


func _apply_modifier(modifier: StatBlock) -> void:
	# Need to make sure stats can be added or multiplied
	assert(modifier.type != Type.NONE, "Modifiers should not be NONE Type.")
	var modification: Callable
	match modifier.type:
		Type.ADD:
			modification = _add_modifier
		Type.MULTIPLY:
			modification = _multiply_modifier
	for stat: StringName in _get_stat_names():
		modification.call(stat, modifier)


func _add_modifier(stat: StringName, modifier: StatBlock) -> void:
	set(stat, get(stat) + modifier.get(stat))


func _multiply_modifier(stat: StringName, modifier: StatBlock) -> void:
	set(stat, get(stat) * modifier.get(stat))
