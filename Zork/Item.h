#pragma once
#include "Entity.h"
class Room;

enum ItemType
{
    KEY_RING,
    KEY,
    CARD
};
class Item :
    public Entity
{
public:
    Item(const char* name, const char* description, Room* location, ItemType itemType);

    ItemType itemType;
};



