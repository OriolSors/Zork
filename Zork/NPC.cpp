#include "NPC.h"

NPC::NPC(const char* name, const char* description, Room* location): Creature(name, description, location)
{
	type = EntityType::NPC_CHARACTER;
}

string NPC::Awake()
{
	rescued = true;

	return "Thank you!";
}
