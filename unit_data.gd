class_name UnitData
extends Node

@export var base_stats: StatSet
# Consider how to handle special non-stat modifiers
@export var modifiers: Dictionary[StringName, StatModifierSet]


func calculate_stats() -> Dictionary[StringName, Variant]:
	# Consider negative indexing support
	# Also calculate time complexity
	var result: Dictionary[StringName, Variant] = base_stats.get_stats()
	var modifier_list: Array[StatSet] = []
	for modifier: StatModifierSet in modifiers.values():
		var index: int = 2 * modifier.priority
		if modifier.type == StatModifierSet.Type.ADDITIVE:
			index += 1
		if index >= modifier_list.size():
			modifier_list.resize(index + 1)
		modifier_list[index] = modifier.values
	for i: int in range(modifier_list.size()):
		var modifier_list_stats: Dictionary[StringName, Variant] = modifier_list[i].get_stats()
		if i % 2 != 0:
			for stat: StringName in result:
				result[stat] += modifier_list_stats[stat]
		else:
			for stat: StringName in result:
				result[stat] *= modifier_list_stats[stat]
	return result
