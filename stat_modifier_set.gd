class_name StatModifierSet
extends Resource

enum Type {
	ADDITIVE,
	MULTIPLICATIVE,
}

@export var name: StringName
@export var values: StatSet
@export var type: Type
@export var priority: int
