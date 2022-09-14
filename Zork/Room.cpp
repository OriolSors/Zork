#include "Room.h"

Room::Room(const char* name, const char* description): Entity(name, description, NULL)
{
	type = EntityType::ROOM;
}

Item* Room::GetItem(ItemType itemType)
{
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* item = (Item*)entity;
			if (item->itemType == itemType) {
				return item;
			}
		}
	}

	return NULL;
}

NPC* Room::TalkNPC()
{
	for (auto entity : contains) {
		if (entity->type == NPC_CHARACTER) {
			NPC* npc = (NPC*)entity;
			return npc;
		}
	}

	return NULL;
}
