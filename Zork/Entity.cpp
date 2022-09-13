#include "Entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL):
	name(name), description(description), parent(parent)
{

	entityType = ENTITY;

	if (parent != NULL) {
		parent->contains.push_back(this);
	}
}
