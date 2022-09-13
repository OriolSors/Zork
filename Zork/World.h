#pragma once
#include <list>
#include "Entity.h"
using namespace std;
class World
{
public:
	World();
	~World();

	list<Entity*> entities;

};

