#include "Entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL):
	name(name), description(description), parent(parent)
{

	type = ENTITY;

	if (this->parent != NULL) {
		this->parent->contains.push_back(this);
	}
}

void Entity::ChangeParent(Entity* newParent)
{

	if (this->parent != NULL)
		this->parent->contains.remove(this);

	this->parent = newParent;

	if (this->parent != NULL)
		this->parent->contains.push_back(this);
}

void Entity::Update()
{
}
