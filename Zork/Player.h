#pragma once
#include "Creature.h"
#include "Item.h"
#include "NPC.h"
class Player :
    public Creature
{
public:
    Player(const char* name, const char* description, Room* location);

    void Open(Room* destinationRoom);

    void Pick(Item* item);

    void Drop(Item* item);

    void Rescue(NPC* npc);

    void Insert(Item* item1, Item* item2);
};

