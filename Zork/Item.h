#pragma once
#include "Entity.h"
#include "Room.h"
class Item :
    public Entity
{
public:
    Item(const char* name, const char* description, Room* location);
};

