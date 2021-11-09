#include "BabdulGame.h";

class Series
{
	int seriesLength = 7;

	int gamesPlayed = 0;

	int team1Wins = 0;
	int team2Wins = 0;

	BabdulManager babMan;

public:

	Series(BabdulManager& babMan)
	{
		this->babMan = babMan;
	}

	void setUpSeries()
	{
		system("cls");
		cout << "Welcome to the Series gamemode!" << endl << endl;
		cout << "Please enter a series length (best of 3, 5, 7): ";
		cin >> seriesLength;
		if (seriesLength == 3 || seriesLength == 5 || seriesLength == 7)
		{
			cout << seriesLength << " game series selected." << endl;
		}
		else
		{
			cout << "Invalid series length. Defaulting to a best of 3 series." << endl;
			seriesLength = 3;
		}
		cout << endl;

		system("pause");
		system("cls");
	}

	void playSeries()
	{
		setUpSeries();

		while (gamesPlayed < seriesLength && team1Wins < ((seriesLength / 2) + 0.5) && team2Wins < ((seriesLength / 2) + 0.5))
		{
			preGame();

			BabdulGame game(babMan);
			if (game.playGame(babMan.gameLength, babMan.otLength, true, gamesPlayed + 1, seriesLength) == 1)
			{
				team1Wins++;
			}
			else
			{
				team2Wins++;
			}

			checkSeriesEnd();

			gamesPlayed++;
		}
	}

	void preGame()
	{
		system("cls");

		cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
		cout << babMan.team1.getTeamName() << " | " << team1Wins << " : " << team2Wins << " | " << babMan.team2.getTeamName() << endl;
		cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;

		cout << "Welcome to game " << gamesPlayed + 1 << "!" << endl;
	}

	void checkSeriesEnd()
	{
		if (team1Wins > (seriesLength / 2))
		{
			system("cls");

			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << babMan.team1.getTeamName() << " | " << team1Wins << " : " << team2Wins << " | " << babMan.team2.getTeamName() << endl;
			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << endl;
			cout << "CONGRATULATIONS " << babMan.team1.getTeamName() << "! You have won the series!" << endl;
		}
		if (team2Wins > (seriesLength / 2))
		{
			system("cls");

			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << babMan.team1.getTeamName() << " | " << team1Wins << " : " << team2Wins << " | " << babMan.team2.getTeamName() << endl;
			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << endl;
			cout << "CONGRATULATIONS " << babMan.team2.getTeamName() << "! You have won the series!" << endl;
		}
	}



};