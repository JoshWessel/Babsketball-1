#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>

#include "GameModeManager.h"

using namespace std;

// Ideas to add:

// - Alternate game modes
//		- Regular Game (current thing)
//		- 7 Game Series (series length can be specified)
//		- 3 Point Contest
// - Add more attributes
//		- Fatigue
//		- Clutch Factor
// - Add quarters / halftime
// - Add pause menu options
//		- Adjust matchups
//		- Call timeout
// - Combine pregame menus into a single menu

int main()
{
	// Set Random Seed
	srand(time(0));

	// Set Window Size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, 1920, 1050, TRUE);




	GameModeManager gameModeManager;
	gameModeManager.welcome();





}