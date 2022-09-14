#include "Exit.h"
Exit::Exit(const char* name, const char* description, Room* source, Direction direction, Room* destination):
	Entity(name, description, source),
	source(source), direction(direction), destination(destination)
	
{
	type = EntityType::EXIT;
}

