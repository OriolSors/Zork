#include "Item.h"

Item::Item(const char* name, const char* description, Room* location): Entity(name, description, location)
{
	entityType = EntityType::ITEM;
}
