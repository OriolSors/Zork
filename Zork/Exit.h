#pragma once
#include "Entity.h"
#include "Room.h"
class Exit :
    public Entity
{
public:
	Exit(const char* name, const char* description, Room* source);

	Room* source;
	Direction direction;
	Room* destination;

};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

