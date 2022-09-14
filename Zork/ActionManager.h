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

	Direction GetDirectionFromString(string direction);
	void GetItemFromString(string item);
	void DropItemFromString(string item);
	void RescueNPC();
	void InsertItemToItem(string item1, string item2);
	void Open();
	void Pick();
	void Drop();
	void Rescue();
	void Insert();
	void ErrorInputAction();
	void ErrorLengthPredicate(string action, string correctLength);
};

