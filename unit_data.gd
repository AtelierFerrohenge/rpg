class_name UnitData
extends Node

@export var base_stats: StatSet
# Consider how to handle special non-stat modifiers
@export var modifiers: Dictionary[StringName, StatModifierSet]
