
#include <iostream>
#include <string>
#include "World.h"
#include "ActionManager.h"

using namespace std;

int main()
{
	cout << "Welcome to house. Find the prisoner and get out together.\n You can quit game with 'exit'." << endl;
	World* world = new World();
	ActionManager* actionManager = new ActionManager(world);

	while (true)
	{
		string sentence;
		getline(cin, sentence);
		if (sentence == "exit") break;
		actionManager->SplitAction(sentence);
		if (actionManager->finishedGame) break;
		
	}
	cout << "Game finished!" << endl;
	system("pause");
	return 0;
}


