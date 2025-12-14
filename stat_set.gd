class_name StatSet
extends Resource

# Consider how to handle special non-stat modifiers
# Review the system to add more getters and setters
@export var _base_stats: StatBlock = null:
	set = _set_base_stats
# Refresh myself on clean/dirty caching
var total: StatBlock = null:
	get = _get_total
var _total_dirty: bool = true
# Review the need for two layers of Dictionaries
var _modifiers: Dictionary[StringName, StatBlock] = {}
var _modifier_sets: Array[ModifierSet] = []


func set_modifier(name: StringName, modifier: StatBlock) -> void:
	_modifiers[name] = modifier
	var priority_index: int = _calculate_priority_index(modifier)
	if priority_index > _modifier_sets.size():
		_modifier_sets.resize(priority_index + 1)
	if _modifier_sets[priority_index] == null:
		_modifier_sets[priority_index] = ModifierSet.new(StatBlock.Type.ADD if priority_index % 2 != 0 else StatBlock.Type.MULTIPLY)
	_modifier_sets[priority_index].set_modifier(name, modifier)
	_total_dirty = true


func erase_modifier(name: StringName) -> void:
	var modifier: StatBlock = _modifiers.get(name)
	assert(modifier != null, "Attempting to remove nonexistent modifier.")
	var priority_index: int = _calculate_priority_index(modifier)
	_modifier_sets[priority_index].erase_modifier(name)
	_modifiers.erase(name)
	_total_dirty = true


func _set_base_stats(value: StatBlock) -> void:
	assert(value.type == StatBlock.Type.NONE, "Base stats should not be a modifier Type.")
	assert(value.priority == -1, "Base stats should not have a modifier priority.")
	_base_stats = value


func _get_total() -> StatBlock:
	if _total_dirty:
		_calculate_total()
	return total


func _calculate_priority_index(modifier: StatBlock) -> int:
	assert(modifier.type != StatBlock.Type.NONE, "Modifiers should not be NONE Type.")
	assert(modifier.priority >= 0, "Modifiers should not be negative priority.")
	var result: int = 2 * modifier.priority
	if modifier.type == StatBlock.Type.ADD:
		result += 1
	return result


func _calculate_total() -> void:
	total = _base_stats
	var last_valid_index: int = 0
	for i in range(_modifier_sets.size()):
		if _modifier_sets[i] != null:
			var modifier_total: StatBlock = _modifier_sets[i].total
			if modifier_total != null:
				total = total.modify_with(modifier_total)
				last_valid_index = i
	if last_valid_index + 1 != _modifier_sets.size():
		_modifier_sets.resize(last_valid_index)
	_total_dirty = false


class ModifierSet:
	var total: StatBlock = null:
		get = _get_total
	var _total_dirty: bool = true
	# Review the need for this guardrail
	var _type: StatBlock.Type
	var _modifiers: Dictionary[StringName, StatBlock] = {}


	func _init(type: StatBlock.Type) -> void:
		_type = type


	func set_modifier(name: StringName, modifier: StatBlock) -> void:
		assert(modifier.type == _type, "Attempting to set the wrong type of modifier for this ModifierSet.")
		_modifiers[name] = modifier
		_total_dirty = true


	func erase_modifier(name: StringName) -> void:
		var erased: bool = _modifiers.erase(name)
		assert(erased, "Attempted to erase nonexistent modifier.")
		_total_dirty = true


	func _get_total() -> StatBlock:
		if _total_dirty:
			_calculate_total()
		return total


	func _calculate_total() -> void:
		total = null
		for modifier in _modifiers.values():
			if total != null:
				total = total.modify_with(modifier)
			else:
				total = modifier
		_total_dirty = false
