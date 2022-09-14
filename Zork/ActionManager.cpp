#include "ActionManager.h"
#include "World.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <sstream>
ActionManager::ActionManager(World* world): world(world)
{
}

void ActionManager::SplitAction(string action)
{
	if (action == "") {
		ErrorInputAction();
	}else{
		istringstream iss(action);
		string input;
		while (iss >> input) {
			actionSplitted.push_back(input);
		}

		string actionVerb = actionSplitted[0];
		if (actionVerb == "open") {
			Open();
		}
		else if (actionVerb == "pick") {
			Pick();
		}
		else if (actionVerb == "drop") {
			Drop();
		}
		else if (actionVerb == "rescue") {
			Rescue();
		}
		else if (actionVerb == "insert") {
			Insert();
		}
		else {
			ErrorInputAction();
		}
		actionSplitted.clear();
	}

}

void ActionManager::Open()
{
	if (actionSplitted.size() != 2) {
		ErrorLengthPredicate("open","2");
	}
	else if (actionSplitted[1] != "north" && actionSplitted[1] != "south" && actionSplitted[1] != "east" && actionSplitted[1] != "west") {
		cout << "Direction not valid. Please, try with: north, south, east, west" << endl;
	}else {
		Direction direction = GetDirectionFromString(actionSplitted[1]);
		Exit* exit = world->GetExit((Room*)world->player->parent, direction);
		if (exit && exit->destination) {
			world->player->Open(exit->destination);
		}
		else if (exit && !exit->destination) {
			//Check NPC rescued in GameManager and WIN or LOSE
		}
		else {
			cout << "There is no door in this direction. Try again" << endl;
		}
	}
}



void ActionManager::Pick()
{
	if (actionSplitted.size() != 2) {
		ErrorLengthPredicate("pick", "2");
	}
	else if (actionSplitted[1] != "key" && actionSplitted[1] != "card" && actionSplitted[1] != "minibag") {
		cout << "Item not valid. Please, try with: key, card, minibag" << endl;
	}
	else {
		GetItemFromString(actionSplitted[1]);
	}
}

void ActionManager::Drop()
{
	if (actionSplitted.size() != 2) {
		ErrorLengthPredicate("drop", "2");
	}
	else if (actionSplitted[1] != "key" && actionSplitted[1] != "card" && actionSplitted[1] != "minibag") {
		cout << "Item not valid. Please, try with: key, card, minibag" << endl;
	}
	else {
		DropItemFromString(actionSplitted[1]);
	}
}

void ActionManager::Rescue()
{
	if (actionSplitted.size() != 2) {
		ErrorLengthPredicate("rescue", "2");
	}
	else if (actionSplitted[1] != "prisoner") {
		cout << "Character does not exist. Please, try with: prisoner" << endl;
	}
	else {
		RescueNPC();
	}
}

void ActionManager::Insert()
{
	if (actionSplitted.size() != 3) {
		ErrorLengthPredicate("insert", "3");
	}
	else {
		InsertItemToItem(actionSplitted[1], actionSplitted[2]);
	}
}

void ActionManager::ErrorInputAction() {
	cout << "Input action not valid. Please, make a sentence with one of the following words: open, pick, drop, rescue, insert" << endl;
}

void ActionManager::ErrorLengthPredicate(string action, string correctLength) {
	cout << "Incorrect sentence length. For action " + action + ", length must be " + correctLength << endl;
}

void ActionManager::GetItemFromString(string itemName) {
	Room* currentRoom = (Room*)world->player->parent;
	Item* itemRetrieved = nullptr;
	if (itemName == "key") {
		itemRetrieved = currentRoom->GetItem(ItemType::KEY);
	}
	else if (itemName == "card") {
		itemRetrieved = currentRoom->GetItem(ItemType::CARD);
	}
	else if (itemName == "minibag") {
		itemRetrieved = currentRoom->GetItem(ItemType::KEY_RING);
	}
	
	if (itemRetrieved) {
		world->player->Pick(itemRetrieved);

	}
	else {
		cout << "This item is not here" << endl;
	}
}

void ActionManager::DropItemFromString(string itemName) {
	if (itemName == "key") {
		world->player->Drop(ItemType::KEY);
	}
	else if (itemName == "card") {
		world->player->Drop(ItemType::CARD);
	}
	else if (itemName == "minibag") {
		world->player->Drop(ItemType::KEY_RING);
	}
}

void ActionManager::RescueNPC() {
	Room* currentRoom = (Room*)world->player->parent;
	NPC* npc = currentRoom->TalkNPC();
	if (npc) {
		world->player->Rescue(npc);
	}
	else {
		cout << "This character is not here" << endl;
	}
}

void ActionManager::InsertItemToItem(string item1, string item2)
{
	if (item2 != "minibag") {
		cout << "You cannot place any object to " + item2 << endl;
	}
	else if (item1 == "key") {
		world->player->Insert(ItemType::KEY, ItemType::KEY_RING);
		
	}
	else if (item1 == "card") {
		world->player->Insert(ItemType::CARD, ItemType::KEY_RING);
	}else {
		cout << "The " + item1 + " does not exist" << endl;
	}
}

Direction ActionManager::GetDirectionFromString(string direction) {
	if (direction == "north") {
		return Direction::NORTH;
	}
	else if (direction == "east") {
		return Direction::EAST;
	}
	else if (direction == "south") {
		return Direction::SOUTH;
	}
	else if (direction == "west") {
		return Direction::WEST;
	}
}

