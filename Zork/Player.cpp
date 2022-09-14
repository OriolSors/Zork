#include "Player.h"
#include "NPC.h"
#include "Room.h"
#include "Item.h"
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
	item->ChangeParent(this);
	cout << "You obtained " + item->name << endl;
}

void Player::Drop(ItemType itemType)
{
	string message = "You don't have this item";
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
	bool cardObtained = false;
	bool keyObtained = false;
	Item* itemAux = nullptr;
	for (auto entity : contains) {
		if (entity->type == ITEM) {
			Item* item = (Item*)entity;
			if (item->itemType == CARD) {
				itemAux = item;
				cardObtained = true;
			}
			if (item->itemType == KEY) {
				keyObtained = true;
			}

			if (cardObtained && keyObtained) break;
		}
	}
	if (itemAux && keyObtained) {
		this->contains.remove(itemAux);
		string npcMessage = npc->Awake();
		cout << "Prisoner: " + npcMessage << endl;
		cout << "You rescued the prisoner and give him his card" << endl;
	}
	else if (keyObtained){
		cout << "Mmmm... you don't know who is this guy... Is there any information out there?" << endl;
	}
	else {
		cout << "Mmmm... you will need first a key" << endl;
	}
	
	
}

void Player::Insert(ItemType item1, ItemType item2)
{
	Item* littleItem = nullptr;
	Item* bigItem = nullptr;
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
