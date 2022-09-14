#include "Item.h"
Item::Item(const char* name, const char* description, Room* location, ItemType itemType): Entity(name, description, location), itemType(itemType)
{
	type = EntityType::ITEM;
}

