#include "Player.h"

Player::Player(const char* name, const char* description, Room* location): Creature(name, description, location)
{
	type = EntityType::PLAYER;
}

void Player::Open(Room* destinationRoom)
{
	ChangeParent(destinationRoom);
}

void Player::Pick(Item* item)
{
	this->contains.push_back(item);
}

void Player::Drop(Item* item)
{
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* itemAux = (Item*)entity;
			if (itemAux->itemType == item->itemType) {
				item->ChangeParent(this->parent);
			}
		}
	}
}

void Player::Rescue(NPC* npc)
{
	npc->Awake();
}

void Player::Insert(Item* item1, Item* item2)
{
	item1->ChangeParent(item2);
}
