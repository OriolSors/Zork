#include "Exit.h"

Exit::Exit(const char* name, const char* description, Room* source): Entity(name, description, source)
{
	entityType = EntityType::EXIT;
}
