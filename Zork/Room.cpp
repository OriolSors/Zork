#include "Room.h"

Room::Room(const char* name, const char* description): Entity(name, description, NULL)
{
	entityType = EntityType::ROOM;
}
