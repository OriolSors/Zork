#pragma once
#include "World.h"
#include "Room.h"

class ActionManager
{
public:
	ActionManager(World* world);
	World* world;

	vector<string> actionSplitted;
	void SplitAction(string action);

	void Open();
	Direction GetDirectionFromString(string direction);

	void Pick();
	void GetItemFromString(string item);

	void Drop();
	void DropItemFromString(string item);

	void Rescue();
	void RescueNPC();

	void Insert();
	void InsertItemToItem(string item1, string item2);

	void Inventory();

	void ErrorInputAction();
	void ErrorLengthPredicate(string action, string correctLength);

	bool rescued = false;
	bool finishedGame = false;
};

