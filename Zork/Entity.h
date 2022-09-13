
#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	string name;
	string description;
	list<Entity*> contains;
	EntityType entityType;
	Entity* parent;


	virtual void Update();

};

enum EntityType
{
	ENTITY,
	CREATURE,
	NPC,
	PLAYER,
	EXIT,
	ROOM,
	ITEM
};

