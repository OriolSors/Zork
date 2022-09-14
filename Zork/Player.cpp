#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const char* name, const char* description, Room* location): Creature(name, description, location)
{
	type = EntityType::PLAYER;
}

void Player::Open(Room* destinationRoom)
{
	ChangeParent(destinationRoom);
	cout << destinationRoom->description << endl;
}

void Player::Pick(Item* item)
{
	this->contains.push_back(item);
	cout << "You obtained " + item->name << endl;
}

void Player::Drop(ItemType itemType)
{
	string message = "You don't have ";
	string itemName;
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* itemAux = (Item*)entity;
			if (itemAux->itemType == itemType) {
				itemAux->ChangeParent(this->parent);
				message = "You dropped ";
				itemName = itemAux->name;
				break;
			}
		}
	}
	cout << message + itemName << endl;
}

void Player::Rescue(NPC* npc)
{
	Item* itemAux = nullptr;
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* item = (Item*)entity;
			if (item->itemType == CARD) {
				itemAux = item;
				break;
			}
		}
	}
	if (itemAux) {
		this->contains.remove(itemAux);
		npc->Awake();
		cout << "You rescued the prisoner and give him his card" << endl;
	}
	else {
		cout << "Mmmm... you don't know who is this guy... Is there any information out there?" << endl;
	}
	
	
}

void Player::Insert(ItemType item1, ItemType item2)
{
	Item* littleItem;
	Item* bigItem;
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* item = (Item*)entity;
			if (item->itemType = item1) {
				littleItem = item;
			}
			else if (item->itemType = item2) {
				bigItem = item;
			}
		}
	}
	if (littleItem && bigItem) {
		littleItem->ChangeParent(bigItem);
		cout << "Item " + littleItem->name + " inserted into " + bigItem->name << endl;
	}
	else {
		cout << "You don't have one or both items" << endl;
	}
	
}

list<string> Player::Inventory()
{
	list<string> items;
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* item = (Item*)entity;
			items.push_back(item->name);
		}
	}
	return items;
}
