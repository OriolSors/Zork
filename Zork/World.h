#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"
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

