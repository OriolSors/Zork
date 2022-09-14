#pragma once
#include "Entity.h"
class NPC;
#include "Item.h"
class Room :
    public Entity
{
public:
    Room(const char* name, const char* description);

    Item* GetItem(ItemType itemType);
    NPC* TalkNPC();
};

