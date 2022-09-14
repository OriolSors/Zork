#pragma once
#include "Entity.h"
#include "NPC.h"
class Room :
    public Entity
{
public:
    Room(const char* name, const char* description);

    Item* GetItem(ItemType itemType);
    NPC* TalkNPC();
};

