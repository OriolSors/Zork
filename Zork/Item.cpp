#include "Item.h"
Item::Item(const char* name, const char* description, Room* location, ItemType itemType): Entity(name, description, location), itemType(itemType)
{
	entityType = EntityType::ITEM;
}

