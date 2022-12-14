#pragma once
#include <string>
#include <list>
using namespace std;
enum EntityType
{
	ENTITY,
	CREATURE,
	NPC_CHARACTER,
	PLAYER,
	EXIT,
	ROOM,
	ITEM
};
class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	string name;
	string description;
	list<Entity*> contains;
	EntityType type;
	Entity* parent;


	void ChangeParent(Entity* newParent);

	virtual void Update();

};



