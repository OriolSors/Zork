#pragma once
#include <vector>

class Entity;
class Player;
#include "Exit.h"

using namespace std;
class World
{
public:
	World();
	~World();

	Player* player;
	vector<Entity*> entities;

	Exit* GetExit(Room* source, Direction direction);
};

