#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* location): 
	Entity(name, description, location)
{
	entityType = EntityType::CREATURE;
}
