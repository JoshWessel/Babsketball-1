#include "Series.h"

class GameModeManager
{
	int gameModeSelected = -1;

public:

	void welcome()
	{
		while (gameModeSelected != 0)
		{
			system("cls");
			cout << "O=====================================================================================================================================O" << endl;
			cout << "|                                         -   -   -      B A B S K E T B A L L      -   -   -                                         |" << endl;
			cout << "O=====================================================================================================================================O" << endl << endl;

			cout << "Available Game Modes" << endl;
			cout << endl;
			cout << "     (0) Quit" << endl;
			cout << endl;
			cout << "     (1) Quick Game" << endl;
			cout << "     (2) Series" << endl;
			cout << "     (3) 3-Point Contest" << endl;

			cout << endl << "Please Select A Game Mode: ";
			cin >> gameModeSelected;

			// Single Game
			if (gameModeSelected == 1)
			{
				cout << endl << endl << "Loading Quick Game..." << endl << endl;
				system("pause");

				// Setup Teams
				BabdulManager babManager;
				if (babManager.setup(25) > 0)
				{
					BabdulGame game(babManager);
					game.playGame(babManager.gameLength, babManager.otLength, false, 1, 1);
				}
			}
			else if (gameModeSelected == 2)
			{
				cout << endl << endl << "Loading Series..." << endl << endl;
				system("pause");

				// Setup Teams
				BabdulManager babManager;
				if (babManager.setup(25) > 0)
				{
					Series series(babManager);
					series.playSeries();
				}
			}
			else if (gameModeSelected == 3)
			{
				cout << endl << endl << "Loading 3-Point Contest..." << endl << endl;
				system("pause");
				
			}
			else if (gameModeSelected == 0)
			{
				cout << endl << "Thanks for Playing!" << endl << endl;
				system("pause");
			}
			else
			{
				cout << endl << "Game Mode not found..." << endl << endl;
				system("pause");
			}

		}
	}
	

};



