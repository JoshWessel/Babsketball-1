#include "BabdulManager.h"

#define BC team1.players.at(currPlayerIndex)
#define DF team2.players.at(randDefenderIndex)

class BabdulGame
{
	int numUsers = 1;

	int team1Score = 0;
	int team2Score = 0;

	int shotClock = 5;
	int time = 0;
	int gameLength;
	int shotClockLength = 5;

	int tipOff = 1;

	int numPasses;
	int numDrives;
	int numCurrDrives;
	bool changePossession = false;

	bool isOvertime = false;

	bool isASeries = false;
	int gameNumber = 1;
	int gamesInSeries = 1;
	
	BabdulManager babMan;

	Sliders gameSliders;

public:

	BabdulGame(BabdulManager& babMan)
	{
		this->babMan = babMan;
		numUsers = babMan.numUsers;

		gameLength = babMan.gameLength;
		shotClockLength = babMan.shotClockLength;
	}

	void resetPossession()
	{
		shotClock = shotClockLength;
		numPasses = 0;
		numDrives = 0;
		numCurrDrives = 0;
		changePossession = true;
	}

	void resetShotClock()
	{
		shotClock = shotClockLength;
	}

	void applyGameSlidersToPlayers()
	{
		// Team 1
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).sliders = gameSliders;
		}

		// Team 2
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).sliders = gameSliders;
		}
	}

	void applyGameSlidersToPlayers(Team team)
	{
		for (int i = 0; i < team.getNumPlayers(); i++)
		{
			team.players.at(i).sliders = gameSliders;
		}
	}

	int playGame(int timeLimit, int overtimeLimit, bool isASeries, int gameNumberInSeries, int gamesInSeries)
	{
		if (isASeries)
		{
			this->isASeries = true;
			this->gameNumber = gameNumberInSeries;
			this->gamesInSeries = gamesInSeries;
		}

		system("cls");
		babMan.printTeam(babMan.team1);
		babMan.printTeam(babMan.team2);

		applyGameSlidersToPlayers();

		cout << endl << endl;

		// Tipoff
		tipOff = rand() % 2 + 1;
		if (tipOff == 1)
		{
			cout << "======================"; for (int i = 0; i < babMan.team1.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << babMan.team1.getTeamName() << " has won the tipoff..." << endl;
			cout << "======================"; for (int i = 0; i < babMan.team1.getTeamName().length(); i++) { cout << "="; } cout << endl;
			
			if (numUsers >= 1)
			{
				cout << endl << "Please select a player to start with: ";
				string startPlayer;
				cin >> startPlayer;

				if (startPlayer.length() < 7)
					startPlayer = startPlayer + " ";

				bool startPlayerFound = false;
				for (int i = 0; i < babMan.team1.players.size(); i++)
				{
					string newBabName = babMan.team1.players.at(i).getBabName();
					transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
					string startPlayerToLower = startPlayer;
					transform(startPlayerToLower.begin(), startPlayerToLower.end(), startPlayerToLower.begin(), ::tolower);

					if (startPlayerToLower == newBabName)
					{
						babMan.team1.players.at(i).setBallCarrier(true);
						cout << endl << babMan.team1.players.at(i).getBabName() << " has the ball to start." << endl << endl;
						babMan.team1.players.at(i).printStats();
						startPlayerFound = true;
					}
				}

				if (startPlayerFound == false)
				{
					cout << "Start player " << startPlayer << " not found. Defaulting to shortest player..." << endl;
					babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).setBallCarrier(true);
					cout << endl << babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
					babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).printStats();
				}
			}
			else
			{
				cout << endl << "AI selecting starting player..." << endl;
				babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).setBallCarrier(true);
				cout << endl << babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
				babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).printStats();
			}
		}
		else if (tipOff == 2)
		{
			cout << "======================"; for (int i = 0; i < babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << babMan.team2.getTeamName() << " has won the tipoff..." << endl;
			cout << "======================"; for (int i = 0; i < babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			
			if (numUsers >= 2)
			{
				cout << endl << "Please select a player to start with: ";
				string startPlayer;
				cin >> startPlayer;

				if (startPlayer.length() < 7)
					startPlayer = startPlayer + " ";

				bool startPlayerFound = false;
				for (int i = 0; i < babMan.team2.players.size(); i++)
				{
					string newBabName = babMan.team2.players.at(i).getBabName();
					transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
					string startPlayerToLower = startPlayer;
					transform(startPlayerToLower.begin(), startPlayerToLower.end(), startPlayerToLower.begin(), ::tolower);

					if (startPlayerToLower == newBabName)
					{
						babMan.team2.players.at(i).setBallCarrier(true);
						cout << endl << babMan.team2.players.at(i).getBabName() << " has the ball to start." << endl << endl;
						babMan.team2.players.at(i).printStats();
						startPlayerFound = true;
					}
				}

				if (startPlayerFound == false)
				{
					cout << "Start player " << startPlayer << " not found. Defaulting to shortest player..." << endl;
					babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).setBallCarrier(true);
					cout << endl << babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
					babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).printStats();
				}
			}
			else
			{
				cout << endl << "AI selecting starting player..." << endl;
				babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).setBallCarrier(true);
				cout << endl << babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
				babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).printStats();
			}
		}

		cout << endl;
		system("pause");

		// Game loop
		if (numUsers == 0 || numUsers == 1 || numUsers == 2)
		{
			gameLoop(numUsers, timeLimit);
		}
		else
		{
			cout << "Invalid number of users" << endl;
		}

		system("cls");
		cout << babMan.team1.getTeamName() << " " << team1Score << ":" << team2Score << " " << babMan.team2.getTeamName() << endl << endl;

		if (team1Score > team2Score)
			cout << babMan.team1.getTeamName() << " Wins!" << endl << endl;
		else if (team2Score > team1Score)
			cout << babMan.team2.getTeamName() << " Wins!" << endl << endl;
		else
		{
			if (isASeries)
				return overtime(overtimeLimit);
			else
				overtime(overtimeLimit);
		}

		printBoxScore();

		// Cleanup
		resetPoints();

		if (isASeries)
		{
			if (team1Score > team2Score)
				return 1;
			else
				return 2;
		}
		else
		{
			//exitApplication();
			return 0;
		}
	}

	void gameLoop(int numPlayers, int timeLimit)
	{
		// No Players (AI vs AI)
		if (numPlayers == 0)
		{
			// Player 1 starts
			if (tipOff == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, true); // AI
					}
				}
			}
			// Player 2 starts
			else if (tipOff == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, true); // AI
					}
				}
			}
			
		}
		// 1 Player
		else if (numPlayers == 1)
		{
			// Player 1 starts
			if (tipOff == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, false);
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, true); // AI
					}
				}
			}
			// Player 2 starts
			else if (tipOff == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, false);
					}
				}
			}
		}
		// 2 Player
		else if (numPlayers == 2)
		{
			// Player 1 starts
			if (tipOff == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, false);
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, false);
					}
				}
			}
			// Player 2 starts
			else if (tipOff == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, false);
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, false);
					}
				}
			}
		}
	}

	int overtime(int overtimeLimit)
	{
		cout << "We're tied! Get ready for overtime..." << endl << endl;
		system("pause");

		system("cls");

		time = 0;

		isOvertime = true;

		gameLoop(numUsers, overtimeLimit);

		system("cls");
		cout << babMan.team1.getTeamName() << " " << team1Score << ":" << team2Score << " " << babMan.team2.getTeamName() << endl << endl;

		if (team1Score > team2Score)
			cout << babMan.team1.getTeamName() << " Wins!" << endl << endl;
		else if (team2Score > team1Score)
			cout << babMan.team2.getTeamName() << " Wins!" << endl << endl;
		else
			overtime(overtimeLimit);

		if (isASeries)
		{
			if (team1Score > team2Score)
				return 1;
			else
				return 2;
		}
		else
		{
			return 0;
		}
	}

	void resetPoints()
	{
		team1Score = 0;
		team2Score = 0;

		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).setPoints(0);
		}

		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).setPoints(0);
		}
	}

	void printCourt(Team& t)
	{
		string pos1 = "      ";
		string pos2 = "      ";
		string pos3 = "      ";
		string pos4 = "      ";
		string pos5 = "      ";
		string pos6 = "      ";
		string pos7 = "  |   ";
		
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			if (t.players.at(i).getLocation() == 1)
				pos1 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 2)
				pos2 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 3)
				pos3 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 4)
				pos4 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 5)
				pos5 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 6)
				pos6 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 7)
				pos7 = t.players.at(i).getBabName();
			else
				cout << t.players.at(i).getBabName() << " has an invalid position" << endl;
		}
		
		cout << "|----------------------------------" << endl;
		cout << "|  " << pos4 << endl;
		cout << "|--------------------. " << endl;
		cout << "|                     \\ " << endl;
		cout << "|                      \\ " << endl;
		cout << "|                       \\ " << pos2 << endl;
		cout << "|                        \\ " << endl;
		cout << "|--------------------     \\ " << endl;
		cout << "|                   |--.   \\ " << endl;
		cout << "|  ---.             |   \\   | " << endl;
		cout << "|  |   \\            |    \\   | " << endl;
		cout << "|  |O" << pos7 << pos6 << "   |     |   | " << pos1 << endl;
		cout << "|  |   /            |    /   | " << endl;
		cout << "|  ---'             |   /   | " << endl;
		cout << "|                   |--'   / " << endl;
		cout << "|--------------------     / " << endl;
		cout << "|                        / " << endl;
		cout << "|                       / " << pos3 << endl;
		cout << "|                      / " << endl;
		cout << "|                     / " << endl;
		cout << "|--------------------' " << endl;
		cout << "|  " << pos5 << endl;
		cout << "|----------------------------------" << endl << endl;
	}

	void printTeamAttributes(Team& t, Babdul& bc, Babdul& defender)
	{
		vector<Babdul> tempTeam = babMan.sortBy(t.players, "Overall");
		cout << "Babname Position Overall Tier       Build         Babdulishness S-Close S-Mid S-3 PSAC Off-Reb Speed Strength Points Blocks Assists" << endl;
		cout << "===================================================================================================================================" << endl;
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			Babdul p = tempTeam.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getBabdulishness() << "            " <<
				p.getShotClose() << "      " <<
				p.getShotMid() << "    " <<
				p.getShot3() << "  " <<
				p.getPassAccuracy() << "   " <<
				p.getOffRebound() << "      " <<
				p.getSpeed() << "    " <<
				p.getStrength() << "       " <<
				p.getPoints() << "      " <<
				p.getBlocks() << "      " <<
				p.getAssists() << 
				endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
		printOffensivePlayerAttributes(bc);
		printDefenderAtttributes(defender);
	}

	void printDefenderAtttributes(Babdul defender)
	{
		cout << endl << "Defended By:" << endl << endl;
		cout << "Babname Position Overall Tier       Build         Babdulishness Per-D Int-D S-Contest Block Def-Reb Points Blocks Assists" << endl;
		cout << "=========================================================================================================================" << endl;
		cout << defender.getBabName() << " " <<
			defender.getPosition() << "       " <<
			defender.getOverall() << "      " <<
			defender.getTier() << " " <<
			defender.getBuild() << " " <<
			defender.getBabdulishness() << "            " <<
			defender.getPerimeterD() << "    " <<
			defender.getInteriorD() << "    " <<
			defender.getShotContest() << "        " <<
			defender.getBlock() << "    " <<
			defender.getDefRebound() << "      " <<
			defender.getPoints() << "      " <<
			defender.getBlocks() << "      " <<
			defender.getAssists() << 
			endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	}

	void printOffensivePlayerAttributes(Babdul player)
	{
		cout << endl << "Ball Carrier:" << endl << endl;
		cout << "Babname Position Overall Tier       Build         Babdulishness S-Close S-Mid S-3 PSAC Off-Reb Speed Strength Points Blocks Assists" << endl;
		cout << "===================================================================================================================================" << endl;
		cout << player.getBabName() << " " <<
			player.getPosition() << "       " <<
			player.getOverall() << "      " <<
			player.getTier() << " " <<
			player.getBuild() << " " <<
			player.getBabdulishness() << "            " <<
			player.getShotClose() << "      " <<
			player.getShotMid() << "    " <<
			player.getShot3() << "  " <<
			player.getPassAccuracy() << "   " <<
			player.getOffRebound() << "      " <<
			player.getSpeed() << "    " <<
			player.getStrength() << "       " <<
			player.getPoints() << "      " <<
			player.getBlocks() << "      " <<
			player.getAssists() <<
			endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}

	void printBoxScore()
	{
		babMan.team1.players = babMan.sortBy(babMan.team1.players, "Points");
		cout << endl << babMan.team1.getTeamName() << endl << endl;
		cout << "Babname Position Overall Tier       Build         Points Rebounds Assists Blocks" << endl;
		cout << "================================================================================" << endl;
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			Babdul p = babMan.team1.players.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "        " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}

		babMan.team2.players = babMan.sortBy(babMan.team2.players, "Points");
		cout << endl << babMan.team2.getTeamName() << endl << endl;
		cout << "Babname Position Overall Tier       Build         Points Rebounds Assists Blocks" << endl;
		cout << "================================================================================" << endl;
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			Babdul p = babMan.team2.players.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "        " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}

		system("pause");
	}

	void scoreBoard(Team& team1)
	{
		int timeRemaining = gameLength - time;
		if (isOvertime)
			timeRemaining = babMan.otLength - time;

		for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length() + 49; i++) { cout << "="; }
		if ((gameLength - time) > 9) { cout << "="; }
		cout << "==========================="; for (int i = 0; i < team1.getTeamName().length(); i++) { cout << "="; } cout << "===========================================" << endl;

		cout << babMan.team1.getTeamName() << " " << team1Score << ":" << team2Score << " " << babMan.team2.getTeamName() << "     Time Remaining: " << timeRemaining << "     SHOTCLOCK: " << shotClock << "     ";
		cout << "POSSESSION --------------- " << team1.getTeamName() << " --------------- POSSESSION     Game " << gameNumber << " of " << gamesInSeries << endl;

		for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length() + 49; i++) { cout << "="; }
		if ((gameLength - time) > 9) { cout << "="; }
		cout << "==========================="; for (int i = 0; i < team1.getTeamName().length(); i++) { cout << "="; } cout << "===========================================" << endl;
	}

	void possession(Team& team1, Team& team2, int currTeamNum, bool AIPossession)
	{
		babMan.assignLocations(team1);

		resetShotClock();

		changePossession = false;
		while (!changePossession && time < gameLength)
		{
			system("cls");
			scoreBoard(team1);

			int currTeam, oppoTeam;

			if (currTeamNum == 1)
			{
				currTeam = 1;
				oppoTeam = 2;
			}
			else if (currTeamNum == 2)
			{
				currTeam = 2;
				oppoTeam = 1;
			}
			else
			{
				cout << "Invalid team number" << endl;
				return;
			}

			// Set matchups based on height
			team1.players = babMan.sortBy(team1.players, "height");
			team2.players = babMan.sortBy(team2.players, "height");

			// Find Ball Carrier and his matchup
			int currPlayerIndex = 0;
			int randDefenderIndex = 0;

			for (int i = 0; i < team1.getNumPlayers(); i++)
			{
				if (team1.players.at(i).getBallCarrier() == true)
				{
					currPlayerIndex = i;
					randDefenderIndex = i + numDrives;
					if (randDefenderIndex >= 5)
						randDefenderIndex -= 5;
				}
			}

			printCourt(team1);
			printTeamAttributes(team1, BC, team2.players.at(randDefenderIndex));

			// Shot clock turnover
			if (shotClock == 0)
			{
				cout << endl << "Shot clock turnover." << endl << endl;
				resetPossession();
				switchBallCarriers(BC, DF);
				team1.players.at(findPasserIndex(team1)).setWasPasser(false);
				if (time < gameLength)
				{
					if (!AIPossession)
						if (numUsers == 1)
							outletPass(team2, team1, DF, true);
						else
							outletPass(team2, team1, DF, false);
					else
						if (numUsers == 1)
							outletPass(team2, team1, DF, false);
						else
							outletPass(team2, team1, DF, true);
				}
			}
			// If time left on shotclock
			else
			{
				cout << endl << "Team " << currTeam << "'s " << BC.getBabName() << " currently has the ball. He is being defended by Team " << oppoTeam << "'s " << DF.getBabName() << "." << endl;

				char psd;
				// AI Decision
				if (AIPossession)
				{
					psd = AI_Decision(BC, DF);

					string choice;
					if (psd == 's')
						choice = "shoot";
					else if (psd == 'p')
						choice = "pass";
					else if (psd == 'd')
						choice = "drive";
					else if (psd == 'b')
						choice = "back down";

					cout << endl << "AI chooses to " << choice << " with " << BC.getBabName() << "." << endl;
				}
				// Player Decision
				else
				{
					cout << endl << "Press '/' to pause. Would you like to pass (p), drive (d), back down (b), shoot (s), hold (h), or do something Babdulish (!) with " << BC.getBabName() << "? ";
					cin >> psd;
				}

				if (psd == '/' && !AIPossession)
				{
					pauseMenu(team1);
				}
				else if (psd == '!' && !AIPossession)
				{
					int miracleShot = rand() % 10 + 1;
					if (miracleShot == 10)
					{
						int points;
						if (BC.getLocation() < 6)
							points = 3;
						else
							points = 2;

						if (currTeamNum == 1)
							team1Score += points;
						else if (currTeamNum == 2)
							team2Score += points;

						cout << endl << BC.getBabName() << " Scored!" << endl << endl;

						BC.addPoints(points);
						BC.printStats();

						if (numPasses > 0)
							team1.players.at(findPasserIndex(team1)).addAssist();

						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}
					else
					{
						int randMessage = rand() % 12 + 1;
						if (randMessage == 1)
						{
							cout << endl << "So close! But actually not really..." << endl;
						}
						else if (randMessage == 2)
						{
							cout << endl << BC.getBabName() << " passes to the ref..." << endl;
						}
						else if (randMessage == 3)
						{
							cout << endl << BC.getBabName() << " tries to do a backflip and winds up with a broken nose. But it's probably fine..." << endl;
						}
						else if (randMessage == 4 && BC.getLocation() != 6 && BC.getLocation() != 7)
						{
							cout << endl << BC.getBabName() << " attempts a standing dunk from the 3 point line. So of course that didn't work..." << endl;
						}
						else if (randMessage == 4)
						{
							cout << endl << BC.getBabName() << " falls asleep and turns it over. He gets stepped on by " << DF.getBabName() << ", so that woke " << BC.getBabName() << " up and he's fine." << endl;
						}
						else if (randMessage == 5)
						{
							cout << endl << "You probably regret choosing this option. But here's a smiley face to help you feel better :)" << endl;
						}
						else if (randMessage == 6)
						{
							cout << endl << BC.getBabName() << " has an existential crisis while contemplating the suspicious coincidence that everybody's name ends in abdul, and no one has any last names...and then he turns it over..." << endl;
						}
						else if (randMessage == 7)
						{
							cout << endl << BC.getBabName() << " has an alergic reaction to the air, and turns it over..." << endl;
						}
						else if (randMessage == 8)
						{
							cout << endl << BC.getBabName() << " looked at the defense, saw that they were sad, and thought he'd cheer them up by giving them the ball..." << endl;
						}
						else if (randMessage == 9)
						{
							cout << endl << BC.getBabName() << " remembers that he doesn't know how to play basketball, drops the ball, and runs away crying...but he's back on defense so it's ok" << endl;
						}
						else if (randMessage == 10)
						{
							cout << endl << BC.getBabName() << " looks in his reflection off the floor, has a heart attack, dies, revives himself with the power of sheer babdulishness, and then gets back on defense..." << endl;
						}
						else if (randMessage == 11)
						{
							cout << endl << BC.getBabName() << " gets sneezed on by the defender and blatantly flops trying to draw a foul. Little does " << BC.getBabName() << " know that there are no fouls in Babsketball, or refs..." << endl;
						}
						else if (randMessage == 12)
						{
							cout << endl << BC.getBabName() << " is a babdul. So that's a turnover..." << endl;
						}
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}
				}
				else if (psd == 'h' || psd == 'H')
				{
					cout << endl << BC.getBabName() << " holds the ball." << endl << endl;

					// Shot clock warning
					if (shotClock == 1)
					{
						cout << endl << "WARNING: Shot clock is winding down..." << endl;
					}
				}
				else if (psd == 's' || psd == 'S')
				{
					bool shotAttempt = BC.shoot(DF, numPasses, numDrives);
					bool blockAttempt;
					if (BC.getHeightInInches() >= DF.getHeightInInches() + 4)
						blockAttempt = false;
					else
						blockAttempt = DF.attemptBlock();

					// Shot attempt is successful, defense is unable to defend
					if (shotAttempt && !blockAttempt)
					{
						int points;
						if (BC.getLocation() < 6)
							points = 3;
						else
							points = 2;

						if (currTeamNum == 1)
							team1Score += points;
						else if (currTeamNum == 2)
							team2Score += points;

						cout << endl << BC.getBabName() << " Scored!" << endl << endl;

						BC.addPoints(points);
						BC.printStats();

						if (numPasses > 0)
							team1.players.at(findPasserIndex(team1)).addAssist();

						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					// shot attempt is on target, but defense blocks the shot
					else if (blockAttempt)
					{
						cout << endl << DF.getBabName() << " blocks " << BC.getBabName() << "!" << endl << endl;

						team2.players.at(randDefenderIndex).addBlock();
						team2.players.at(randDefenderIndex).printStats();

						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					// shot attempt is unsuccessful
					else if (!shotAttempt)
					{
						cout << endl << BC.getBabName() << " missed." << endl << endl;
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						findRebounder(team1, team2);

						// Check offensive rebounders
						for (int i = 0; i < team1.getNumPlayers(); i++)
						{
							if (team1.players.at(i).getIsRebounder() == true)
							{
								cout << "OFFENSIVE REBOUND: ";
								cout << team1.players.at(i).getBabName() << " (" << team1.players.at(i).getOffRebound() << " off reb) gets the offensive rebound!" << endl;
								team1.players.at(i).addOffRebound();
								team1.players.at(i).setIsRebounder(false);

								shotClock = shotClockLength;
								numPasses = 0;
								numDrives = 0;
								numCurrDrives = 0;

								switchBallCarriers(BC, team1.players.at(i));
							}
						}
						// Check defensive rebounders
						for (int i = 0; i < team2.getNumPlayers(); i++)
						{
							if (team2.players.at(i).getIsRebounder() == true)
							{
								cout << "Defensive rebound: ";
								cout << team2.players.at(i).getBabName() << " (" << team2.players.at(i).getDefRebound() << " def reb) gets the defensive rebound." << endl;
								team2.players.at(i).addDefRebound();
								team2.players.at(i).setIsRebounder(false);

								resetPossession();
								switchBallCarriers(BC, team2.players.at(i));

								if (time < gameLength)
								{
									if (!AIPossession)
										if (numUsers == 1)
											outletPass(team2, team1, DF, true);
										else
											outletPass(team2, team1, DF, false);
									else
										if (numUsers == 1)
											outletPass(team2, team1, DF, false);
										else
											outletPass(team2, team1, DF, true);
								}
							}
						}
					}
				}
				else if (psd == 'p' || psd == 'P')
				{
					string passTo;
					bool targetFound = false;
					int checkedTeammates = 0;
					if (AIPossession)
					{
						// Randomly find a pass target on the AI's team
						int passTarget = rand() % 5;

						// Increment the target if they try to pass to themselves
						if (BC.getBabName() == team1.players.at(passTarget).getBabName())
						{
							if (passTarget == 0)
								passTarget++;
							else
								passTarget--;
						}

						passTo = team1.players.at(passTarget).getBabName();
						cout << "AI attempts to pass the ball to " << passTo << endl;
					}
					else
					{
						cout << "Which teammate would you like to pass the ball to? ";
						cin >> passTo;
					}

					if (passTo.length() == 6)
						passTo = passTo + " ";

					// If the target is the ball carrier
					if (passTo == BC.getBabName() && !AIPossession)
					{
						cout << BC.getBabName() << " unsuccessfully passes to himself, turning it over." << endl;
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}

					for (int i = 0; i < team1.getNumPlayers(); i++)
					{
						string newBabName = team1.players.at(i).getBabName();
						transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
						string newPassTo = passTo;
						transform(newPassTo.begin(), newPassTo.end(), newPassTo.begin(), ::tolower);

						if (newBabName == newPassTo)
						{
							// Pass attempt is successful
							targetFound = true;
							bool passAttempt = BC.pass(DF, numPasses, numDrives);

							if (passAttempt)
							{
								cout << endl << endl << "SUCCESS " << BC.getBabName() << " passes to " << passTo << "." << endl << endl;
								numPasses++;
								numCurrDrives = 0;

								if (BC.getLocation() > 5)
									exitPaint(BC, team1);

								switchBallCarriers(BC, team1.players.at(i));
								if (numPasses > 0)
									switchPasser(team1.players.at(findPasserIndex(team1)), BC);
								else
									BC.setWasPasser(true);

								// Shot clock warning
								if (shotClock == 1)
								{
									cout << endl << "WARNING: Shot clock is winding down..." << endl;
								}
							}
							// Pass attempt is unsuccessful
							else
							{
								cout << endl << BC.getBabName() << " turns it over while trying to pass to " << passTo << "." << endl << endl;
								resetPossession();
								switchBallCarriers(BC, DF);
								team1.players.at(findPasserIndex(team1)).setWasPasser(false);
								if (time < gameLength)
								{
									if (!AIPossession)
										if (numUsers == 1)
											outletPass(team2, team1, DF, true);
										else
											outletPass(team2, team1, DF, false);
									else
										if (numUsers == 1)
											outletPass(team2, team1, DF, false);
										else
											outletPass(team2, team1, DF, true);
								}
							}
							checkedTeammates = 0;
						}

						if (targetFound)
							break;

						checkedTeammates++;
						if (checkedTeammates >= 5)
						{
							cout << endl << passTo << " is on the bench! " << BC.getBabName() << " turns it over while trying to pass to " << passTo << " on the bench." << endl << endl;
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);
							if (time < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else if (psd == 'd' || psd == 'D')
				{
					// Player drives out of bounds
					if (numCurrDrives > 2)
					{
						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					else
					{
						bool driveAttempt = BC.drive(DF, numPasses, numDrives);

						// Drive is successful
						if (driveAttempt)
						{
							numDrives++;
							numCurrDrives++;
							if (numCurrDrives == 1)
							{
								cout << endl << BC.getBabName() << " drives. They are currently at the free throw line." << endl << endl;
								BC.setLocation(6);
							}
							else if (numCurrDrives == 2)
							{
								cout << endl << BC.getBabName() << " drives. They are currently at the basket." << endl << endl;
								BC.setLocation(7);
							}
							else
							{
								cout << endl << BC.getBabName() << " drives." << endl << endl;
							}

							// Shot clock warning
							if (shotClock == 1)
							{
								cout << "WARNING: Shot clock is winding down..." << endl;
							}
						}
						// Drive is not successful
						else
						{
							cout << endl << BC.getBabName() << " turns it over." << endl << endl;
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);
							if (time < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else if (psd == 'b' || psd == 'B')
				{
					// Player drives out of bounds
					if (numCurrDrives > 2)
					{
						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
						if (time < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					else
					{
						bool backDownAttempt = BC.backDown(DF);

						// Drive is successful
						if (backDownAttempt)
						{
							numDrives++;
							numCurrDrives++;
							if (numCurrDrives == 1)
							{
								cout << endl << BC.getBabName() << " backs down the defender. They are currently in the high post." << endl << endl;
								BC.setLocation(6);
							}
							else if (numCurrDrives == 2)
							{
								cout << endl << BC.getBabName() << " backs down the defender. They are currently at the basket." << endl << endl;
								BC.setLocation(7);
							}
							else
							{
								cout << endl << BC.getBabName() << " backs down the defender." << endl << endl;
							}

							// Shot clock warning
							if (shotClock == 1)
							{
								cout << "WARNING: Shot clock is winding down..." << endl;
							}
						}
						// Drive is not successful
						else
						{
							cout << endl << BC.getBabName() << " turns it over." << endl << endl;
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);
							if (time < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else
				{
					cout << "Invalid option. " << BC.getBabName() << " does nothing and turns the ball over.";
					resetPossession();
					switchBallCarriers(BC, DF);
					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
					if (time < gameLength)
					{
						if (!AIPossession)
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						else
							if (numUsers == 1)
								outletPass(team2, team1, DF, false);
							else
								outletPass(team2, team1, DF, true);
					}
				}

				shotClock--;
				time++;

				system("pause");
				cout << endl;
			}
		}
	}

	//void possession(Team& team1, Team& team2, int currTeamNum)
	//{
	//	babMan.assignLocations(team1);
	//
	//	resetShotClock();
	//	
	//	changePossession = false;
	//	while (!changePossession && time < gameLength)
	//	{
	//		system("cls");
	//		scoreBoard(team1);
	//		
	//		int currTeam, oppoTeam;
	//
	//		if (currTeamNum == 1)
	//		{
	//			currTeam = 1;
	//			oppoTeam = 2;
	//		}
	//		else if (currTeamNum == 2)
	//		{
	//			currTeam = 2;
	//			oppoTeam = 1;
	//		}
	//		else
	//		{
	//			cout << "Invalid team number" << endl;
	//			return;
	//		}
	//
	//		// Set matchups based on height
	//		team1.players = babMan.sortBy(team1.players, "height");
	//		team2.players = babMan.sortBy(team2.players, "height");
	//
	//		// Find Ball Carrier and his matchup
	//		int currPlayerIndex = 0;
	//		int randDefenderIndex = 0;
	//
	//		for (int i = 0; i < team1.getNumPlayers(); i++)
	//		{
	//			if (team1.players.at(i).getBallCarrier() == true)
	//			{
	//				currPlayerIndex = i;
	//				randDefenderIndex = i + numDrives;
	//				if (randDefenderIndex >= 5)
	//					randDefenderIndex -= 5;
	//			}
	//		}
	//
	//		printCourt(team1);
	//		printTeamAttributes(team1, BC, team2.players.at(randDefenderIndex));
	//
	//		// Shot clock turnover
	//		if (shotClock == 0)
	//		{
	//			cout << endl << "Shot clock turnover." << endl << endl;
	//			resetPossession();
	//			switchBallCarriers(BC, DF);
	//			team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//			if (time < gameLength)
	//			{
	//				if (numUsers == 1)
	//					outletPass(team2, team1, DF, true);
	//				else
	//					outletPass(team2, team1, DF, false);
	//			}
	//		}
	//		// If time is left on the shotclock
	//		else
	//		{
	//			cout << endl << "Team " << currTeam << "'s " << BC.getBabName() << " currently has the ball. He is being defended by Team " << oppoTeam << "'s " << DF.getBabName() << "." << endl;
	//
	//			char psd;
	//			cout << endl << "Press '/' to pause. Would you like to pass (p), drive (d), back down (b), shoot (s), hold (h), or do something Babdulish (!) with " << BC.getBabName() << "? ";
	//			cin >> psd;
	//
	//			if (psd == '/')
	//			{
	//				pauseMenu(team1);
	//			}
	//			else if (psd == '!')
	//			{
	//				int miracleShot = rand() % 10 + 1;
	//				if (miracleShot == 10)
	//				{
	//					int points;
	//					if (BC.getLocation() < 6)
	//						points = 3;
	//					else
	//						points = 2;
	//
	//					if (currTeamNum == 1)
	//						team1Score += points;
	//					else if (currTeamNum == 2)
	//						team2Score += points;
	//
	//					cout << endl << BC.getBabName() << " Scored!" << endl << endl;
	//
	//					BC.addPoints(points);
	//					BC.printStats();
	//
	//					if (numPasses > 0)
	//						team1.players.at(findPasserIndex(team1)).addAssist();
	//
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				else
	//				{
	//					int randMessage = rand() % 12 + 1;
	//					if (randMessage == 1)
	//					{
	//						cout << endl << "So close! But actually not really..." << endl;
	//					}
	//					else if (randMessage == 2)
	//					{
	//						cout << endl << BC.getBabName() << " passes to the ref..." << endl;
	//					}
	//					else if (randMessage == 3)
	//					{
	//						cout << endl << BC.getBabName() << " tries to do a backflip and winds up with a broken nose. But it's probably fine..." << endl;
	//					}
	//					else if (randMessage == 4 && BC.getLocation() != 6 && BC.getLocation() != 7)
	//					{
	//						cout << endl << BC.getBabName() << " attempts a standing dunk from the 3 point line. So of course that didn't work..." << endl;
	//					}
	//					else if (randMessage == 4)
	//					{
	//						cout << endl << BC.getBabName() << " falls asleep and turns it over. He gets stepped on by " << DF.getBabName() << ", so that woke " << BC.getBabName() << " up and he's fine." << endl;
	//					}
	//					else if (randMessage == 5)
	//					{
	//						cout << endl << "You probably regret choosing this option. But here's a smiley face to help you feel better :)" << endl;
	//					}
	//					else if (randMessage == 6)
	//					{
	//						cout << endl << BC.getBabName() << " has an existential crisis while contemplating the suspicious coincidence that everybody's name ends in abdul, and no one has any last names...and then he turns it over..." << endl;
	//					}
	//					else if (randMessage == 7)
	//					{
	//						cout << endl << BC.getBabName() << " has an alergic reaction to the air, and turns it over..." << endl;
	//					}
	//					else if (randMessage == 8)
	//					{
	//						cout << endl << BC.getBabName() << " looked at the defense, saw that they were sad, and thought he'd cheer them up by giving them the ball..." << endl;
	//					}
	//					else if (randMessage == 9)
	//					{
	//						cout << endl << BC.getBabName() << " remembers that he doesn't know how to play basketball, drops the ball, and runs away crying...but he's back on defense so it's ok" << endl;
	//					}
	//					else if (randMessage == 10)
	//					{
	//						cout << endl << BC.getBabName() << " looks in his reflection off the floor, has a heart attack, dies, revives himself with the power of sheer babdulishness, and then gets back on defense..." << endl;
	//					}
	//					else if (randMessage == 11)
	//					{
	//						cout << endl << BC.getBabName() << " gets sneezed on by the defender and blatantly flops trying to draw a foul. Little does " << BC.getBabName() << " know that there are no fouls in Babsketball, or refs..." << endl;
	//					}
	//					else if (randMessage == 12)
	//					{
	//						cout << endl << BC.getBabName() << " is a babdul. So that's a turnover..." << endl;
	//					}
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//			}
	//			else if (psd == 'h' || psd == 'H')
	//			{
	//				cout << endl << BC.getBabName() << " holds the ball." << endl << endl;
	//
	//				// Shot clock warning
	//				if (shotClock == 1)
	//				{
	//					cout << endl << "WARNING: Shot clock is winding down..." << endl;
	//				}
	//			}
	//			else if (psd == 's' || psd == 'S')
	//			{
	//				bool shotAttempt = BC.shoot(DF, numPasses, numDrives);
	//				bool blockAttempt = DF.attemptBlock();
	//
	//				// Shot attempt is successful, defense is unable to defend
	//				if (shotAttempt && !blockAttempt)
	//				{
	//					int points;
	//					if (BC.getLocation() < 6)
	//						points = 3;
	//					else
	//						points = 2;
	//
	//					if (currTeamNum == 1)
	//						team1Score += points;
	//					else if (currTeamNum == 2)
	//						team2Score += points;
	//
	//					cout << endl << endl << "SUCCESS! " << BC.getBabName() << " Scored!" << endl << endl;
	//
	//					BC.addPoints(points);
	//					BC.printStats();
	//
	//					if (numPasses > 0)
	//						team1.players.at(findPasserIndex(team1)).addAssist();
	//
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				// shot attempt is on target, but defense blocks the shot
	//				else if (blockAttempt)
	//				{
	//					cout << endl << DF.getBabName() << " blocks " << BC.getBabName() << "!" << endl << endl;
	//
	//					team2.players.at(randDefenderIndex).addBlock();
	//					team2.players.at(randDefenderIndex).printStats();
	//
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				// shot attempt is unsuccessful
	//				else if (!shotAttempt)
	//				{
	//					cout << endl << BC.getBabName() << " missed." << endl << endl;
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//
	//					findRebounder(team1, team2);
	//
	//					// Check offensive rebounders
	//					for (int i = 0; i < team1.getNumPlayers(); i++)
	//					{
	//						if (team1.players.at(i).getIsRebounder() == true)
	//						{
	//							cout << "OFFENSIVE REBOUND: ";
	//							cout << team1.players.at(i).getBabName() << " (" << team1.players.at(i).getOffRebound() << " off reb) gets the offensive rebound!" << endl;
	//							team1.players.at(i).addOffRebound();
	//							team1.players.at(i).setIsRebounder(false);
	//
	//							shotClock = shotClockLength;
	//							numPasses = 0;
	//							numDrives = 0;
	//							numCurrDrives = 0;
	//
	//							switchBallCarriers(BC, team1.players.at(i));
	//						}
	//					}
	//					// Check defensive rebounders
	//					for (int i = 0; i < team2.getNumPlayers(); i++)
	//					{
	//						if (team2.players.at(i).getIsRebounder() == true)
	//						{
	//							cout << "Defensive rebound: ";
	//							cout << team2.players.at(i).getBabName() << " (" << team2.players.at(i).getDefRebound() << " def reb) gets the defensive rebound." << endl;
	//							team2.players.at(i).addDefRebound();
	//							team2.players.at(i).setIsRebounder(false);
	//
	//							resetPossession();
	//							switchBallCarriers(BC, team2.players.at(i));
	//
	//							if (time < gameLength)
	//							{
	//								if (numUsers == 1)
	//									outletPass(team2, team1, DF, true);
	//								else
	//									outletPass(team2, team1, DF, false);
	//							}
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'p' || psd == 'P')
	//			{
	//				string passTo;
	//				cout << "Which teammate would you like to pass the ball to? ";
	//				cin >> passTo;
	//
	//				if (passTo.length() == 6)
	//					passTo = passTo + " ";
	//
	//				// If the target is the ball carrier
	//				if (passTo == BC.getBabName())
	//				{
	//					cout << BC.getBabName() << " unsuccessfully passes to himself, turning it over." << endl;
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				// If target is not the ball carrier
	//				else
	//				{
	//					bool targetFound = false;
	//
	//					int checkedTeammates = 0;
	//					for (int i = 0; i < team1.getNumPlayers(); i++)
	//					{
	//						string newBabName = team1.players.at(i).getBabName();
	//						transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
	//						string newPassTo = passTo;
	//						transform(newPassTo.begin(), newPassTo.end(), newPassTo.begin(), ::tolower);
	//
	//						if (newBabName == newPassTo)
	//						{
	//							// Pass attempt is successful
	//							targetFound = true;
	//							bool passAttempt = BC.pass(DF, numPasses, numDrives);
	//
	//							if (passAttempt)
	//							{
	//								cout << endl << endl << "SUCCESS " << BC.getBabName() << " passes to " << passTo << "." << endl << endl;
	//								numPasses++;
	//								numCurrDrives = 0;
	//
	//								if (BC.getLocation() > 5)
	//									exitPaint(BC, team1);
	//
	//								switchBallCarriers(BC, team1.players.at(i));
	//								if (numPasses > 0)
	//									switchPasser(team1.players.at(findPasserIndex(team1)), BC);
	//								else
	//									BC.setWasPasser(true);
	//
	//								// Shot clock warning
	//								if (shotClock == 1)
	//								{
	//									cout << endl << "WARNING: Shot clock is winding down..." << endl;
	//								}
	//							}
	//							// Pass attempt is unsuccessful
	//							else
	//							{
	//								cout << endl << BC.getBabName() << " turns it over while trying to pass to " << passTo << "." << endl << endl;
	//								resetPossession();
	//								switchBallCarriers(BC, DF);
	//								team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//								if (time < gameLength)
	//								{
	//									if (numUsers == 1)
	//										outletPass(team2, team1, DF, true);
	//									else
	//										outletPass(team2, team1, DF, false);
	//								}
	//							}
	//							checkedTeammates = 0;
	//						}
	//
	//						if (targetFound)
	//							break;
	//
	//						checkedTeammates++;
	//						if (checkedTeammates >= 5)
	//						{
	//							cout << endl << passTo << " is on the bench! " << BC.getBabName() << " turns it over while trying to pass to " << passTo << " on the bench." << endl << endl;
	//							resetPossession();
	//							switchBallCarriers(BC, DF);
	//							team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//							if (time < gameLength)
	//							{
	//								if (numUsers == 1)
	//									outletPass(team2, team1, DF, true);
	//								else
	//									outletPass(team2, team1, DF, false);
	//							}
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'd' || psd == 'D')
	//			{
	//				// Player drives out of bounds
	//				if (numCurrDrives > 2)
	//				{
	//					cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				else
	//				{
	//					bool driveAttempt = BC.drive(DF, numPasses, numDrives);
	//
	//					// Drive is successful
	//					if (driveAttempt)
	//					{
	//						numDrives++;
	//						numCurrDrives++;
	//						if (numCurrDrives == 1)
	//						{
	//							cout << endl << endl << "SUCCESS " << BC.getBabName() << " drives. They are currently at the free throw line." << endl << endl;
	//							BC.setLocation(6);
	//						}
	//						else if (numCurrDrives == 2)
	//						{
	//							cout << endl << endl << "SUCCESS " << BC.getBabName() << " drives. They are currently at the basket." << endl << endl;
	//							BC.setLocation(7);
	//						}
	//						else
	//						{
	//							cout << endl << endl << "SUCCESS " << BC.getBabName() << " drives." << endl << endl;
	//						}
	//
	//						// Shot clock warning
	//						if (shotClock == 1)
	//						{
	//							cout << "WARNING: Shot clock is winding down..." << endl;
	//						}
	//					}
	//					// Drive is not successful
	//					else
	//					{
	//						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//						resetPossession();
	//						switchBallCarriers(BC, DF);
	//						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//						if (time < gameLength)
	//						{
	//							if (numUsers == 1)
	//								outletPass(team2, team1, DF, true);
	//							else
	//								outletPass(team2, team1, DF, false);
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'b' || psd == 'B')
	//			{
	//				// Player drives out of bounds
	//				if (numCurrDrives > 2)
	//				{
	//					cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, true);
	//						else
	//							outletPass(team2, team1, DF, false);
	//					}
	//				}
	//				else
	//				{
	//					bool backDownAttempt = BC.backDown(DF);
	//
	//					// Drive is successful
	//					if (backDownAttempt)
	//					{
	//						numDrives++;
	//						numCurrDrives++;
	//						if (numCurrDrives == 1)
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender. They are currently in the high post." << endl << endl;
	//							BC.setLocation(6);
	//						}
	//						else if (numCurrDrives == 2)
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender. They are currently at the basket." << endl << endl;
	//							BC.setLocation(7);
	//						}
	//						else
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender." << endl << endl;
	//						}
	//
	//						// Shot clock warning
	//						if (shotClock == 1)
	//						{
	//							cout << "WARNING: Shot clock is winding down..." << endl;
	//						}
	//					}
	//					// Drive is not successful
	//					else
	//					{
	//						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//						resetPossession();
	//						switchBallCarriers(BC, DF);
	//						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//						if (time < gameLength)
	//						{
	//							if (numUsers == 1)
	//								outletPass(team2, team1, DF, true);
	//							else
	//								outletPass(team2, team1, DF, false);
	//						}
	//					}
	//				}
	//			}
	//			else
	//			{
	//				cout << "That is not a valid option. " << BC.getBabName() << " does nothing and turns the ball over.";
	//				resetPossession();
	//				switchBallCarriers(BC, DF);
	//				team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//				if (time < gameLength)
	//				{
	//					if (numUsers == 1)
	//						outletPass(team2, team1, DF, true);
	//					else
	//						outletPass(team2, team1, DF, false);
	//				}
	//			}
	//
	//			shotClock--;
	//			time++;
	//
	//			system("pause");
	//			cout << endl;
	//		}
	//	}
	//}
	//
	//void AIpossession(Team& team1, Team& team2, int currTeamNum)
	//{
	//	babMan.assignLocations(team1);
	//
	//	resetShotClock();
	//
	//	changePossession = false;
	//	while (!changePossession && time < gameLength)
	//	{
	//		system("cls");
	//		scoreBoard(team1);
	//		
	//		int currTeam, oppoTeam;
	//
	//		if (currTeamNum == 1)
	//		{
	//			currTeam = 1;
	//			oppoTeam = 2;
	//		}
	//		else if (currTeamNum == 2)
	//		{
	//			currTeam = 2;
	//			oppoTeam = 1;
	//		}
	//		else
	//		{
	//			cout << "Invalid team number" << endl;
	//			return;
	//		}
	//
	//		// Set matchups based on height
	//		team1.players = babMan.sortBy(team1.players, "height");
	//		team2.players = babMan.sortBy(team2.players, "height");
	//
	//		// Find Ball Carrier and his matchup
	//		int currPlayerIndex = 0;
	//		int randDefenderIndex = 0;
	//
	//		for (int i = 0; i < team1.getNumPlayers(); i++)
	//		{
	//			if (team1.players.at(i).getBallCarrier() == true)
	//			{
	//				currPlayerIndex = i;
	//				randDefenderIndex = i + numDrives;
	//				if (randDefenderIndex >= 5)
	//					randDefenderIndex -= 5;
	//			}
	//		}
	//
	//		printCourt(team1);
	//		printTeamAttributes(team1, BC, team2.players.at(randDefenderIndex));
	//
	//		// Shot clock turnover
	//		if (shotClock == 0)
	//		{
	//			cout << endl << "Shot clock turnover." << endl << endl;
	//			resetPossession();
	//			switchBallCarriers(BC, DF);
	//			team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//			if (time < gameLength)
	//			{
	//				if (numUsers == 1)
	//					outletPass(team2, team1, DF, false);
	//				else
	//					outletPass(team2, team1, DF, true);
	//			}
	//		}
	//		// If time left on shotclock
	//		else
	//		{
	//			cout << endl << "Team " << currTeam << "'s " << BC.getBabName() << " currently has the ball. He is being defended by Team " << oppoTeam << "'s " << DF.getBabName() << "." << endl;
	//			
	//			char psd = AI_Decision(BC, DF);
	//
	//			string choice;
	//			if (psd == 's')
	//				choice = "shoot";
	//			else if (psd == 'p')
	//				choice = "pass";
	//			else if (psd == 'd')
	//				choice = "drive";
	//			else if (psd == 'b')
	//				choice = "back down";
	//
	//			cout << endl << "AI chooses to " << choice << " with " << BC.getBabName() << "." << endl;
	//
	//			if (psd == 's' || psd == 'S')
	//			{
	//				bool shotAttempt = BC.shoot(DF, numPasses, numDrives);
	//				bool blockAttempt;
	//				if (BC.getHeightInInches() >= DF.getHeightInInches() + 4)
	//					blockAttempt = false;
	//				else
	//					blockAttempt = DF.attemptBlock();
	//
	//				// Shot attempt is successful, defense is unable to defend
	//				if (shotAttempt && !blockAttempt)
	//				{
	//					int points;
	//					if (BC.getLocation() < 6)
	//						points = 3;
	//					else
	//						points = 2;
	//
	//					if (currTeamNum == 1)
	//						team1Score += points;
	//					else if (currTeamNum == 2)
	//						team2Score += points;
	//
	//					cout << endl << BC.getBabName() << " Scored!" << endl << endl;
	//
	//					BC.addPoints(points);
	//					BC.printStats();
	//
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, false);
	//						else
	//							outletPass(team2, team1, DF, true);
	//					}
	//				}
	//				// shot attempt is on target, but defense blocks the shot
	//				else if (blockAttempt)
	//				{
	//					cout << endl << DF.getBabName() << " blocks " << BC.getBabName() << "!" << endl << endl;
	//
	//					team2.players.at(randDefenderIndex).addBlock();
	//					team2.players.at(randDefenderIndex).printStats();
	//
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, false);
	//						else
	//							outletPass(team2, team1, DF, true);
	//					}
	//				}
	//				// shot attempt is unsuccessful
	//				else if (!shotAttempt)
	//				{
	//					cout << endl << BC.getBabName() << " missed." << endl << endl;
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//
	//					findRebounder(team1, team2);
	//
	//					// Check offensive rebounders
	//					for (int i = 0; i < team1.getNumPlayers(); i++)
	//					{
	//						if (team1.players.at(i).getIsRebounder() == true)
	//						{
	//							cout << "OFFENSIVE REBOUND: ";
	//							cout << team1.players.at(i).getBabName() << " (" << team1.players.at(i).getOffRebound() << " off reb) gets the offensive rebound!" << endl;
	//							team1.players.at(i).addOffRebound();
	//							team1.players.at(i).setIsRebounder(false);
	//
	//							shotClock = shotClockLength;
	//							numPasses = 0;
	//							numDrives = 0;
	//							numCurrDrives = 0;
	//
	//							switchBallCarriers(BC, team1.players.at(i));
	//						}
	//					}
	//					// Check defensive rebounders
	//					for (int i = 0; i < team2.getNumPlayers(); i++)
	//					{
	//						if (team2.players.at(i).getIsRebounder() == true)
	//						{
	//							cout << "Defensive rebound: ";
	//							cout << team2.players.at(i).getBabName() << " (" << team2.players.at(i).getDefRebound() << " def reb) gets the defensive rebound." << endl;
	//							team2.players.at(i).addDefRebound();
	//							team2.players.at(i).setIsRebounder(false);
	//
	//							resetPossession();
	//							switchBallCarriers(BC, team2.players.at(i));
	//
	//							if (time < gameLength)
	//							{
	//								if (numUsers == 1)
	//									outletPass(team2, team1, DF, false);
	//								else
	//									outletPass(team2, team1, DF, true);
	//							}
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'p' || psd == 'P')
	//			{
	//				// Randomly find a pass target on the AI's team
	//				int passTarget = rand() % 5;
	//
	//				// Increment the target if they try to pass to themselves
	//				if (BC.getBabName() == team1.players.at(passTarget).getBabName())
	//				{
	//					if (passTarget == 0)
	//					{
	//						passTarget++;
	//					}
	//					else
	//					{
	//						passTarget--;
	//					}
	//				}
	//
	//				string passTo = team1.players.at(passTarget).getBabName();
	//				cout << "AI attempts to pass the ball to " << passTo << endl;
	//
	//				if (passTo.length() == 6)
	//					passTo = passTo + " ";
	//
	//				bool targetFound = false;
	//
	//				int checkedTeammates = 0;
	//				for (int i = 0; i < team1.getNumPlayers(); i++)
	//				{
	//					if (team1.players.at(i).getBabName() == passTo)
	//					{
	//						bool passAttempt = BC.pass(DF, numPasses, numDrives);
	//
	//						// Pass attempt is successful
	//						targetFound = true;
	//						if (passAttempt)
	//						{
	//							cout << endl << BC.getBabName() << " passes to " << passTo << "." << endl << endl;
	//							numPasses++;
	//							numCurrDrives = 0;
	//
	//							if (BC.getLocation() > 5)
	//								exitPaint(BC, team1);
	//
	//							switchBallCarriers(BC, team1.players.at(i));
	//
	//							// Shot clock warning
	//							if (shotClock == 1)
	//							{
	//								cout << endl << "WARNING: Shot clock is winding down..." << endl;
	//							}
	//						}
	//						// Pass attempt is unsuccessful
	//						else
	//						{
	//							cout << endl << BC.getBabName() << " turns it over while trying to pass to " << passTo << "." << endl << endl;
	//							resetPossession();
	//							switchBallCarriers(BC, DF);
	//							team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//							if (time < gameLength)
	//							{
	//								if (numUsers == 1)
	//									outletPass(team2, team1, DF, false);
	//								else
	//									outletPass(team2, team1, DF, true);
	//							}
	//						}
	//						checkedTeammates = 0;
	//					}
	//
	//					if (targetFound)
	//						break;
	//
	//					checkedTeammates++;
	//					if (checkedTeammates >= 5)
	//					{
	//						cout << endl << passTo << " is on the bench! " << BC.getBabName() << " turns it over while trying to pass to " << passTo << " on the bench." << endl << endl;
	//						resetPossession();
	//						switchBallCarriers(BC, DF);
	//						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//						if (time < gameLength)
	//						{
	//							if (numUsers == 1)
	//								outletPass(team2, team1, DF, false);
	//							else
	//								outletPass(team2, team1, DF, true);
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'd' || psd == 'D')
	//			{
	//				// Player drives out of bounds
	//				if (numCurrDrives > 2)
	//				{
	//					cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, false);
	//						else
	//							outletPass(team2, team1, DF, true);
	//					}
	//				}
	//				else
	//				{
	//					bool driveAttempt = BC.drive(DF, numPasses, numDrives);
	//
	//					// Drive is successful
	//					if (driveAttempt)
	//					{
	//						numDrives++;
	//						numCurrDrives++;
	//						if (numCurrDrives == 1)
	//						{
	//							cout << endl << BC.getBabName() << " drives. They are currently at the free throw line." << endl << endl;
	//							BC.setLocation(6);
	//						}
	//						else if (numCurrDrives == 2)
	//						{
	//							cout << endl << BC.getBabName() << " drives. They are currently at the basket." << endl << endl;
	//							BC.setLocation(7);
	//						}
	//						else
	//						{
	//							cout << endl << BC.getBabName() << " drives." << endl << endl;
	//						}
	//
	//						// Shot clock warning
	//						if (shotClock == 1)
	//						{
	//							cout << "WARNING: Shot clock is winding down..." << endl;
	//						}
	//					}
	//					// Drive is not successful
	//					else
	//					{
	//						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//						resetPossession();
	//						switchBallCarriers(BC, DF);
	//						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//						if (time < gameLength)
	//						{
	//							if (numUsers == 1)
	//								outletPass(team2, team1, DF, false);
	//							else
	//								outletPass(team2, team1, DF, true);
	//						}
	//					}
	//				}
	//			}
	//			else if (psd == 'b' || psd == 'B')
	//			{
	//				// Player drives out of bounds
	//				if (numCurrDrives > 2)
	//				{
	//					cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//					resetPossession();
	//					switchBallCarriers(BC, DF);
	//					team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//					if (time < gameLength)
	//					{
	//						if (numUsers == 1)
	//							outletPass(team2, team1, DF, false);
	//						else
	//							outletPass(team2, team1, DF, true);
	//					}
	//				}
	//				else
	//				{
	//					bool backDownAttempt = BC.backDown(DF);
	//
	//					// Drive is successful
	//					if (backDownAttempt)
	//					{
	//						numDrives++;
	//						numCurrDrives++;
	//						if (numCurrDrives == 1)
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender. They are currently in the high post." << endl << endl;
	//							BC.setLocation(6);
	//						}
	//						else if (numCurrDrives == 2)
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender. They are currently at the basket." << endl << endl;
	//							BC.setLocation(7);
	//						}
	//						else
	//						{
	//							cout << endl << BC.getBabName() << " backs down the defender." << endl << endl;
	//						}
	//
	//						// Shot clock warning
	//						if (shotClock == 1)
	//						{
	//							cout << "WARNING: Shot clock is winding down..." << endl;
	//						}
	//					}
	//					// Drive is not successful
	//					else
	//					{
	//						cout << endl << BC.getBabName() << " turns it over." << endl << endl;
	//						resetPossession();
	//						switchBallCarriers(BC, DF);
	//						team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//						if (time < gameLength)
	//						{
	//							if (numUsers == 1)
	//								outletPass(team2, team1, DF, false);
	//							else
	//								outletPass(team2, team1, DF, true);
	//						}
	//					}
	//				}
	//			}
	//			else
	//			{
	//				cout << "AI selects an invalid option. " << BC.getBabName() << " does nothing and turns the ball over.";
	//				resetPossession();
	//				switchBallCarriers(BC, DF);
	//				team1.players.at(findPasserIndex(team1)).setWasPasser(false);
	//				if (time < gameLength)
	//				{
	//					if (numUsers == 1)
	//						outletPass(team2, team1, DF, false);
	//					else
	//						outletPass(team2, team1, DF, true);
	//				}
	//			}
	//
	//			shotClock--;
	//			time++;
	//			
	//			system("pause");
	//			cout << endl;
	//		}
	//	}
	//}

	void exitPaint(Babdul& bab, Team& teammates)
	{
		int total = (teammates.getNumPlayers() + 1) * (teammates.getNumPlayers() + 2) / 2;

		for (int i = 0; i < teammates.getNumPlayers(); i++)
		{
			total -= teammates.players.at(i).getLocation();
		}

		bab.setLocation(total);
	}

	void switchBallCarriers(Babdul& oldBC, Babdul& newBC)
	{
		oldBC.setBallCarrier(false);
		newBC.setBallCarrier(true);
	}

	void switchPasser(Babdul& oldBC, Babdul& newBC)
	{
		oldBC.setWasPasser(false);
		newBC.setWasPasser(true);
	}

	char AI_Decision(Babdul& bc, Babdul& df)
	{
		bool AIIsSmart = true;
		int isAISmart = rand() % 10 + 1;

		if (isAISmart < 4)
			AIIsSmart = false;

		if (AIIsSmart)
		{
			if (shotClock <= 1)
				return 's';

			else if (bc.getStrength() > df.getStrength() && bc.getLocation() != 7 && bc.getStrength() > 75)
				return 'b';

			else if (bc.getSpeed() > df.getSpeed() + 5 && bc.getLocation() != 7 && bc.getSpeed() > 75)
				return 'd';

			else if (bc.getShot3() > df.getShotContest() + 10 && bc.getLocation() <= 5 && bc.getShot3() > 80)
				return 's';

			else if (bc.getShotMid() > df.getShotContest() + 10 && bc.getLocation() == 6 && bc.getShotMid() > 80)
				return 's';

			else if (bc.getShotClose() > df.getShotContest() && bc.getLocation() == 7 && bc.getShotClose() > 70)
				return 's';

			else
				return 'p';
		}
		else
		{
			int randDecision = rand() % 4;
			if (randDecision == 0 && bc.getLocation() == 7 && bc.getShotClose() >= 70)
				return 's';
			else if (randDecision == 0 && bc.getLocation() == 6 && bc.getShotMid() >= 70)
				return 's';
			else if (randDecision == 0 && bc.getLocation() <= 5 && bc.getShot3() >= 70)
				return 's';
			else if (randDecision == 1 && bc.getSpeed() >= 70)
				return 'd';
			else if (randDecision == 2 && bc.getStrength() >= 70)
				return 'b';
			else
				return 'p';
		}
	}

	void outletPass(Team& t, Team& t2, Babdul& outletPasser, bool AI)
	{
		system("pause");
		system("cls");

		scoreBoard(t);

		cout << endl;
		cout << "==========================="; for (int i = 0; i < t.getTeamName().length(); i++) { cout << "="; } cout << "===========================" << endl;
		cout << ">>>>>>  FAST  BREAK >>>>>> " << t.getTeamName() << " >>>>>> FAST  BREAK  >>>>>>" << endl;
		cout << "==========================="; for (int i = 0; i < t.getTeamName().length(); i++) { cout << "="; } cout << "===========================" << endl;
		cout << endl;

		printOutletPassOptions(t);

		if (AI)
		{
			t.players = babMan.sortBy(t.players, "speed");
			cout << endl << endl << t.getTeamName() << " selects " << t.players.at(0).getBabName() << " to bring the ball up." << endl << endl;
		}
		else
		{
			string outletTarget;
			cout << endl << endl << outletPasser.getBabName() << " currently has the ball. " << endl << endl;
			cout << "Who would you like to outlet the ball to? (Enter current ball handler's name to bring it up without an outlet pass): ";
			cin >> outletTarget;

			if (outletTarget.length() == 6)
				outletTarget = outletTarget + " ";

			bool foundOutletTarget = false;
			for (int i = 0; i < t.getNumPlayers(); i++)
			{
				string newBabName = t.players.at(i).getBabName();
				transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
				string newOutletTarget = outletTarget;
				transform(newOutletTarget.begin(), newOutletTarget.end(), newOutletTarget.begin(), ::tolower);

				if (newOutletTarget == newBabName)
				{
					switchBallCarriers(outletPasser, t.players.at(i));
					outletPasser.setWasPasser(true);
					cout << endl << endl << t.players.at(i).getBabName() << " will bring the ball up." << endl << endl;
					foundOutletTarget = true;
				}
			}

			if (!foundOutletTarget)
			{
				cout << endl << endl << outletTarget << " is on the bench! " << outletPasser.getBabName() << " will bring the ball up himself." << endl << endl;
			}
		}
	}

	void printOutletPassOptions(Team& t)
	{
		vector<Babdul> tempTeam = babMan.sortBy(t.players, "Overall");
		cout << "Babname Position Overall Tier       Build         Babdulishness S-Close S-Mid S-3 PSAC Off-Reb Speed Strength Points Rebounds Assists Blocks " << endl;
		cout << "=============================================================================================================================================" << endl;
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			Babdul p = tempTeam.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getBabdulishness() << "            " <<
				p.getShotClose() << "      " <<
				p.getShotMid() << "    " <<
				p.getShot3() << "  " <<
				p.getPassAccuracy() << "   " <<
				p.getOffRebound() << "      " <<
				p.getSpeed() << "    " <<
				p.getStrength() << "       " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "       " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " <<
				endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}

	int findPasserIndex(Team team)
	{
		for (int i = 0; i < team.getNumPlayers(); i++)
		{
			if (team.players.at(i).getWasPasser())
			{
				return i;
			}
		}
		return 0;
	}

	void findRebounder(Team& offensiveReboundingTeam, Team& defensiveReboundingTeam)
	{
		int numDefensiveRebounders = rand() % 3 + 2; // 2-4
		int numOffensiveRebounders = rand() % 3 + 0; // 0-2

		offensiveReboundingTeam.players = babMan.sortBy(offensiveReboundingTeam.players, "offReb");
		defensiveReboundingTeam.players = babMan.sortBy(defensiveReboundingTeam.players, "defReb");

		// check for skilled offensive rebounder
		int variation = rand() % 3;
		if (offensiveReboundingTeam.players.at(0).getOffRebound() > defensiveReboundingTeam.players.at(0).getDefRebound() + 5 && variation == 0)
		{
			offensiveReboundingTeam.players.at(0).setIsRebounder(true);
		}
		// random defensive rebounder
		else if (numOffensiveRebounders == 0)
		{
			int randRebounderIndex = rand() % 5; // 0-4
			defensiveReboundingTeam.players.at(randRebounderIndex).setIsRebounder(true);
		}
		// random defensive player from top 3 rebounders
		else if (numDefensiveRebounders >= numOffensiveRebounders + 2)
		{
			int randRebounderIndex = rand() % 3; // 0-2
			defensiveReboundingTeam.players.at(randRebounderIndex).setIsRebounder(true);
		}
		// 50/50
		else
		{
			bool rebounderFound = false;

			for (int i = 0; i < numDefensiveRebounders; i++)
			{
				bool reboundSuccess = defensiveReboundingTeam.players.at(i).attemptDefRebound();
				if (reboundSuccess)
				{
					defensiveReboundingTeam.players.at(i).setIsRebounder(true);
					rebounderFound = true;
				}
			}

			if (!rebounderFound && numOffensiveRebounders > 0)
			{
				for (int i = 0; i < numOffensiveRebounders; i++)
				{
					bool reboundSuccess = offensiveReboundingTeam.players.at(i).attemptOffRebound();
					if (reboundSuccess)
					{
						offensiveReboundingTeam.players.at(i).setIsRebounder(true);
						rebounderFound = true;
					}
				}
			}

			if (!rebounderFound)
			{
				int randRebounderIndex = rand() % 5; // 0-4
				defensiveReboundingTeam.players.at(randRebounderIndex).setIsRebounder(true);
			}
		}
	}

	void restartGame()
	{
		// Reset Player Stats
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).points = 0;
			babMan.team1.players.at(i).rebounds = 0;
			babMan.team1.players.at(i).assists = 0;
			babMan.team1.players.at(i).blocks = 0;
		}
		// Reset Player Stats
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).points = 0;
			babMan.team2.players.at(i).rebounds = 0;
			babMan.team2.players.at(i).assists = 0;
			babMan.team2.players.at(i).blocks = 0;
		}

		team1Score = 0;
		team2Score = 0;

		shotClock = babMan.shotClockLength;
		time = 0;

		isOvertime = false;

		numPasses = 0;
		numDrives = 0;
		numCurrDrives = 0;

		// Create new game
		playGame(babMan.gameLength, babMan.otLength, isASeries, gameNumber, gamesInSeries);
	}

	void pauseMenu(Team& t)
	{
		int option = 0;
		while (option != 1)
		{
			system("cls");

			scoreBoard(t);

			cout << endl;
			cout << "==============================================================================================================" << endl;
			cout << "  <  <  <  <  <  <  <  <  <  <  <  <  <  <  <  <  PAUSE MENU  >  >  >  >  >  >  >  >  >  >  >  >  >  >  >  >  " << endl;
			cout << "==============================================================================================================" << endl;

			cout <<  endl << endl;
			cout << "  ------------------------" << endl;
			cout << "  1 - Return to Game      " << endl;
			cout << "  ------------------------" << endl;
			cout << "  2 - Restart Game        " << endl;
			cout << "  ------------------------" << endl;
			cout << "  3 - Adjust Sliders      " << endl;
			cout << "  ------------------------" << endl;
			
			cout << endl << "Please select one of the above options (enter the option number): ";
			cin >> option;

			cout << endl;
			if (option == 1)
			{
				cout << endl << "Returning to game..." << endl << endl;
			}
			else if (option == 2)
			{
				char confirm;
				cout << endl << "Confirm selection of " << option << "? (y/n) ";
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y')
				{
					cout << "Selection Confirmed" << endl;

					if (option == 2)
					{
						system("cls");
						cout << "The final rosters: " << endl;

						babMan.printTeam(babMan.team1);
						babMan.printTeam(babMan.team2);
						cout << endl;
						restartGame();
					}
					else if (option == 3)
					{
					}
				}
				else
				{
					cout << endl << "Selection Cancelled" << endl;
				}
			}
			else if (option == 3)
			{
				adjustSliders();
			}
			else
			{
				cout << endl << "Invalid selection. Please enter a valid number." << endl << endl;
				system("pause");
			}
		}

		// Prevent time change
		shotClock++;
		time--;
	}

	void adjustSliders()
	{
		int option = 1;

		while (option != 0)
		{
			system("cls");
			gameSliders.printSliders();
			cout << endl;
			cout << "Please select an option to modify the sliders:" << endl;
			cout << "   (0) Back to pause menu" << endl;
			cout << "   (1) Reset sliders to defaults" << endl;
			cout << "   (2) Set all sliders at once" << endl;
			cout << "   (3) Set an individual slider" << endl;
			cout << "   (4) Load slider preset" << endl;
			cout << endl;

			cin >> option;

			// (0) Back to pause menu
			if (option == 0)
			{
				cout << "Returning to pause menu..." << endl;
			}
			// (1) Reset sliders to defaults
			else if (option == 1)
			{
				gameSliders.setSliders("Default", 1.0f);
			}
			// (2) Set all sliders at once
			else if (option == 2)
			{
				float newSlider;
				cout << "Please enter the new slider value (any decimal between 0 and 2): ";
				cin >> newSlider;

				if (newSlider < 0)
					gameSliders.setSliders("Custom", 0);
				else if (newSlider > 2)
					gameSliders.setSliders("Custom", 2);
				else
					gameSliders.setSliders("Custom", newSlider);
			}
			// (3) Set an individual slider
			else if (option == 3)
			{
				int newSliderName = -1;
				float newSliderValue = 1;

				cout << "Please enter the number of the slider you would like to change: ";
				cin >> newSliderName;

				cout << endl << endl;
				
				if (newSliderName == 1)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for babdulishness (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("babdulishness", newSliderValue);
				}
				else if (newSliderName == 2)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot close (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotClose", newSliderValue);
				}
				else if (newSliderName == 3)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot mid (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotMid", newSliderValue);
				}
				else if (newSliderName == 4)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot 3 (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shot3", newSliderValue);
				}
				else if (newSliderName == 5)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for pass accuracy (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("passAccuracy", newSliderValue);
				}
				else if (newSliderName == 6)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for perimeter D (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("perimeterD", newSliderValue);
				}
				else if (newSliderName == 7)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for interior D (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("interiorD", newSliderValue);
				}
				else if (newSliderName == 8)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot contest (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotContest", newSliderValue);
				}
				else if (newSliderName == 9)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for block (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("block", newSliderValue);
				}
				else if (newSliderName == 10)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for def rebound (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("defRebound", newSliderValue);
				}
				else if (newSliderName == 11)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for off rebound (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("offRebound", newSliderValue);
				}
				else if (newSliderName == 12)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for strength (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("strength", newSliderValue);
				}
				else if (newSliderName == 13)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for speed (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("speed", newSliderValue);
				}
				else
				{
					cout << "Invalid number" << endl;
				}
			}
			else if (option == 4)
			{
				// Setup Sliders

				Sliders preset_Default; // Default
				preset_Default.setSliders("Default", 1);

				Sliders preset_AllMaxed; // Max All
				preset_AllMaxed.setSliders("Max All", 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

				Sliders preset_AllMined; // Min All
				preset_AllMined.setSliders("Min All", 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

				Sliders preset_Offense; // Offense Oriented
				preset_Offense.setSliders("Offense Oriented", 0.5, 1.5, 1.5, 1.5, 2, 0.5, 0.5, 0.5, 0.5, 0.5, 1.5, 1.5, 1.5);

				Sliders preset_Defense; // Defense Oriented
				preset_Defense.setSliders("Defense Oriented", 0.8, 0.8, 0.8, 0.8, 0.8, 1.5, 1.5, 1.5, 1.5, 1.5, 0.5, 0.8, 0.8);

				Sliders preset_NoBabdulishness; // No Babdulishness
				preset_NoBabdulishness.setSliders("No Babdulishness", 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

				Sliders preset_PerfectPassing; // Perfect Passing
				preset_PerfectPassing.setSliders("Perfect Passing", 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1);
				
				// Display Options
				system("cls");
				gameSliders.printSlidersHeader();
				cout << "0 Back" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "1 "; preset_Default.printSlidersHorizontally();
				cout << "2 "; preset_AllMaxed.printSlidersHorizontally();
				cout << "3 "; preset_AllMined.printSlidersHorizontally();
				cout << "4 "; preset_Offense.printSlidersHorizontally();
				cout << "5 "; preset_Defense.printSlidersHorizontally();
				cout << "6 "; preset_NoBabdulishness.printSlidersHorizontally();
				cout << "7 "; preset_PerfectPassing.printSlidersHorizontally();
				cout << endl;
				int option;
				cout << "Please enter the number of the desired slider preset: ";
				cin >> option;
				if (option == 0)
				{
					gameSliders = gameSliders;
				}
				else if (option == 1)
				{
					gameSliders = preset_Default;
				}
				else if (option == 2)
				{
					gameSliders = preset_AllMaxed;
				}
				else if (option == 3)
				{
					gameSliders = preset_AllMined;
				}
				else if (option == 4)
				{
					gameSliders = preset_Offense;
				}
				else if (option == 5)
				{
					gameSliders = preset_Defense;
				}
				else if (option == 6)
				{
					gameSliders = preset_NoBabdulishness;
				}
				else if (option == 7)
				{
					gameSliders = preset_PerfectPassing;
				}
				else
				{
					cout << "Invalid Number" << endl;
				}
			}
		}

		applyGameSlidersToPlayers();
	}




};