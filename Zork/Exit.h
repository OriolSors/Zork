#pragma once
#include "Entity.h"
class Room;

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit :
    public Entity
{
public:
	Exit(const char* name, const char* description, Room* source, Direction direction, Room* destination);

	Room* source;
	Direction direction;
	Room* destination;

};



