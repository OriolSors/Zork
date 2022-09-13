#include "Player.h"

Player::Player(const char* name, const char* description, Room* location): Creature(name, description, location)
{
	entityType = EntityType::PLAYER;
}
