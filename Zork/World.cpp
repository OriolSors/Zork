#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Player.h"
#include "NPC.h"

World::World()
{

	Room* room1 = new Room("Room 1", "You are at Ground floor. There is nothing except a light in south direction.");
	Room* room2 = new Room("Room 2", "You are at Garden. You have Living room to the east and Ground floor at north.");
	Room* room3 = new Room("Room 3", "You are at Living room. You can see an extra room to the north, a dark place at south and the Garden at west.");
	Room* room4 = new Room("Room 4", "You are at Prison room. You see a jail... And a door at north.");
	Room* room5 = new Room("Room 5", "You are at Exit room. There is the outside at north. Also you have a door at south.");

	Exit* exit1_2 = new Exit("First door", "First room to Second room", room1, Direction::SOUTH, room2);
	Exit* exit2_1 = new Exit("First door", "Second room to First room", room2, Direction::NORTH, room1);

	Exit* exit2_3 = new Exit("Second door", "Second room to Third room", room2, Direction::EAST, room3);
	Exit* exit3_2 = new Exit("Second door", "Third room to Second room", room3, Direction::WEST, room2);

	Exit* exit3_4 = new Exit("Third door", "Third room to Fourth room", room3, Direction::SOUTH, room4);
	Exit* exit4_3 = new Exit("Third door", "Fourth room to Third room", room4, Direction::NORTH, room3);

	Exit* exit3_5 = new Exit("Fourth door", "Third room to Fifth room", room3, Direction::NORTH, room5);
	Exit* exit5_3 = new Exit("Fourth door", "Fifth room to Third room", room5, Direction::SOUTH, room3);

	Exit* exit5_out = new Exit("Outside door", "Fifth room to exit", room5, Direction::NORTH, NULL);

	player = new Player("Player", "You have to exit the house", room1);
	NPC* npc = new NPC("Prisoner", "He is sleeping inside the bars", room4);
	

	Item* keyRing = new Item("minibag", "Now you can carry certain object.", room3, ItemType::MINIBAG);
	Item* key = new Item("key", "It seems like a prison key. I need to save it properly...", room5, ItemType::KEY);
	Item* card = new Item("card", "It is an identity card. Is there someone here?", room2, ItemType::CARD);

	entities.push_back(room1);
	entities.push_back(room2);
	entities.push_back(room3);
	entities.push_back(room4);
	entities.push_back(room5);
	entities.push_back(exit1_2);
	entities.push_back(exit2_1);
	entities.push_back(exit2_3);
	entities.push_back(exit3_2);
	entities.push_back(exit3_4);
	entities.push_back(exit4_3);
	entities.push_back(exit3_5);
	entities.push_back(exit5_3);
	entities.push_back(exit5_out);
	entities.push_back(player);
	entities.push_back(npc);
	entities.push_back(npc);
	entities.push_back(keyRing);
	entities.push_back(key);
	entities.push_back(card);
}

World::~World()
{
}

Exit* World::GetExit(Room* source, Direction direction)
{
	for (auto entity : entities) {
		if (entity->type == EXIT) {
			Exit* exit = (Exit*)entity;
			if (exit->source == source && exit->direction == direction) {
				return exit;
			}
		}
	}

	return NULL;
}


