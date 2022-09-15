#pragma once
#include "Creature.h"
#include "Item.h"
class NPC;
class Room;
class Player :
    public Creature
{
public:
    Player(const char* name, const char* description, Room* location);

    void Open(Room* destinationRoom);

    void Pick(Item* item);

    void Drop(ItemType itemType);

    void Rescue(NPC* npc, bool& rescued);

    void Insert(ItemType item1, ItemType item2);

    list<string> Inventory();

    Item* minibag;
};

