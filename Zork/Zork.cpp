
#include <iostream>
#include <string>
#include "World.h"
#include "ActionManager.h"

using namespace std;

int main()
{
	cout << "Welcome to house. Find the prisoner and get out together" << endl;
	World* world = new World();
	ActionManager* actionManager = new ActionManager(world);

	while (true)
	{
		string sentence;
		getline(cin, sentence);
		actionManager->SplitAction(sentence);
	}
	cout << "--------------Thanks for playing-------------" << endl;
	cout << "---------------------BYE---------------------" << endl;
	system("pause");
	return 0;
}


