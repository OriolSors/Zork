#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* location): 
	Entity(name, description, (Entity*)location)
{
	type = EntityType::CREATURE;
}
