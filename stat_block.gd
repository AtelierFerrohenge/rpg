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


@abstract func modify_with(modifier: StatBlock) -> StatBlock
