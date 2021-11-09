#include "Sliders.h"

using namespace std;

class Babdul
{
public:
	string babName;
	string position;
	int age;
	int weight;
	pair<int, int> height;

	float babdulishness;
	int overall;

	string tier;
	string build;

	Sliders sliders;

	// Box Score Stats
	int points;
	int blocks;
	int assists;
	int rebounds;

	// Shooting Attributes
	int shotClose;
	int shotMid;
	int shot3;

	// Playmaking Attributes
	int passAccuracy;

	// Defense Attributes
	int perimeterD;
	int interiorD;
	int shotContest;
	int block;

	// Rebounding Attributes
	int defRebound;
	int offRebound;

	// Athmeticism Attributes
	int strength;
	int speed;
	
	int starBoosts = 0;

	int location;

	bool ballCarrier = false;
	bool wasPasser = false;
	bool isRebounder = false;

	bool isInDraft = true;

	vector<string> playerTiers = {
		"Rotation  ",	// +5  - +10
		"Starter   ",	// +10 - +15
		"All-Star  ",	// +15 - +20
		"Superstar "	// +20 - +30
	};

	vector<string> ALL_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Defender     ",
		"Slasher      ",
		"Rebounder    ",
		"Paint_Scorer ",
		"Shot_Blocker "
	};

	vector<string> PG_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Defender     "
	};

	vector<string> SG_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Slasher      ",
		"Defender     "
	};

	vector<string> SF_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Slasher      ",
		"Defender     "
	};

	vector<string> PF_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Rebounder    ",
		"Defender     ",
		"Paint_Scorer ",
		"Shot_Blocker "
	};

	vector<string> C_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Paint_Scorer ",
		"Rebounder    ",
		"Defender     ",
		"Shot_Blocker "
	};

	vector<string> babNames = {
		"Babdul ",
		"Cabdul ",
		"Dabdul ",
		"Fabdul ",
		"Gabdul ",
		"Habdul ",
		"Jabdul ",
		"Kabdul ",
		"Labdul ",
		"Mabdul ",
		"Nabdul ",
		"Pabdul ",
		"Qabdul ",
		"Rabdul ",
		"Sabdul ",
		"Tabdul ",
		"Vabdul ",
		"Wabdul ",
		"Xabdul ",
		"Yabdul ",
		"Zabdul ",

		"Blabdul",
		"Bwabdul",
		"Chabdul",
		"Clabdul",
		"Crabdul",
		"Drabdul",
		"Flabdul",
		"Frabdul",
		"Glabdul",
		"Grabdul",
		"Klabdul",
		"Plabdul",
		"Prabdul",
		"Quabdul",
		"Scabdul",
		"Shabdul",
		"Slabdul",
		"Smabdul",
		"Snabdul",
		"Stabdul",
		"Spabdul",
		"Swabdul",
		"Thabdul",
		"Trabdul",
		"Twabdul",
		"Wrabdul",
		"Zlabdul"
	};

	string generateTier()
	{
		int chance = rand() % 10 + 1;

		if (chance <= 3)				// 1, 2, 3
			return playerTiers.at(0);
		else if (chance <= 7)			// 4, 5, 6, 7
			return playerTiers.at(1);
		else if (chance <= 9)			// 8, 9
			return playerTiers.at(2);
		else if (chance == 10)			// 10
			return playerTiers.at(3);
	}

	string generateBuild(string position)
	{
		if (position == "PG")
		{
			int chance = rand() % PG_Builds.size();
			return PG_Builds.at(chance);
		}
		else if (position == "SG")
		{
			int chance = rand() % SG_Builds.size();
			return SG_Builds.at(chance);
		}
		else if (position == "SF")
		{
			int chance = rand() % SF_Builds.size();
			return SF_Builds.at(chance);
		}
		else if (position == "PF")
		{
			int chance = rand() % PF_Builds.size();
			return PF_Builds.at(chance);
		}
		else if (position == "C ")
		{
			int chance = rand() % C_Builds.size();
			return C_Builds.at(chance);
		}
		else
		{
			cout << "Invalid position. Defaulting to All-Around build" << endl;
			return "All_Around";
		}
	}

	string generatePosition(pair<int, int> height)
	{
		// PG 5,10 -  6,4
		// SG 6,1  -  6,8
		// SF 6,5  -  6,10
		// PF 6,7  -  6,11
		// C  6,9  -  7,7

		if (height.first == 5)
		{
			return "PG";
		}
		else if (height.first == 6)
		{
			if (height.second == 0)
			{
				return "PG";
			}
			else if (height.second == 1)
			{
				int PGorSG_1 = rand() % 10 + 1;
				if (PGorSG_1 < 10)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 2)
			{
				int PGorSG_2 = rand() % 10 + 1;
				if (PGorSG_2 < 9)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 3)
			{
				int PGorSG_3 = rand() % 10 + 1;
				if (PGorSG_3 < 6)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 4)
			{
				int PGorSG_4 = rand() % 10 + 1;
				if (PGorSG_4 < 3)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 5)
			{
				int SGorSF_5 = rand() % 10 + 1;
				if (SGorSF_5 < 8)
				{
					return "SG";
				}
				else
				{
					return "SF";
				}
			}
			else if (height.second == 6)
			{
				int SGorSF_6 = rand() % 10 + 1;
				if (SGorSF_6 < 5)
				{
					return "SG";
				}
				else
				{
					return "SF";
				}
			}
			else if (height.second == 7)
			{
				int SGorSForPF_7 = rand() % 10 + 1;
				if (SGorSForPF_7 < 2)
				{
					return "SG";
				}
				else if (SGorSForPF_7 < 9)
				{
					return "SF";
				}
				else
				{
					return "PF";
				}
			}
			else if (height.second == 8)
			{
				int SForPF_8 = rand() % 10 + 1;
				if (SForPF_8 < 7)
				{
					return "SF";
				}
				else
				{
					return "PF";
				}
			}
			else if (height.second == 9)
			{
				int SForPForC_9 = rand() % 10 + 1;
				if (SForPForC_9 < 5)
				{
					return "SF";
				}
				else if (SForPForC_9 < 10)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
			else if (height.second == 10)
			{
				int SForPForC_10 = rand() % 10 + 1;
				if (SForPForC_10 < 2)
				{
					return "SF";
				}
				else if (SForPForC_10 < 9)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
			else if (height.second == 11)
			{
				int PForC_10 = rand() % 10 + 1;
				if (PForC_10 < 4)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
		}
		else if (height.first == 7)
		{
			return "C ";
		}
	}

	pair<int, int> generateHeight()
	{
		vector<pair<int, int>> heights = {
			
			make_pair(5,10),

			make_pair(5,11),

			make_pair(6,0),
			make_pair(6,0),

			make_pair(6,1),
			make_pair(6,1),

			make_pair(6,2),
			make_pair(6,2),
			make_pair(6,2),

			make_pair(6,3),
			make_pair(6,3),
			make_pair(6,3),
			make_pair(6,3),

			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),

			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),

			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),

			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),

			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),

			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),

			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),

			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),

			make_pair(7,0),
			make_pair(7,0),
			make_pair(7,0),
			make_pair(7,0),

			make_pair(7,1),
			make_pair(7,1),
			make_pair(7,1),

			make_pair(7,2),
			make_pair(7,2),

			make_pair(7,3),

			make_pair(7,4),

			make_pair(7,5),

			make_pair(7,6),

			make_pair(7,7)
		};

		int heightIndex = rand() % heights.size();
		return heights.at(heightIndex);
	}

	int generateWeight(int heightInInches)
	{
		int variation = rand() % 20 - 10;

		if (heightInInches < 72)
			return variation + 180;
		else if (heightInInches < 74)
			return variation + 200;
		else if (heightInInches < 76)
			return variation + 210;
		else if (heightInInches < 78)
			return variation + 220;
		else if (heightInInches < 80)
			return variation + 230;
		else if (heightInInches < 82)
			return variation + 240;
		else if (heightInInches < 84)
			return variation + 250;
		else if (heightInInches < 86)
			return variation + 280;
		else if (heightInInches >= 86)
			return variation + 300;
	}

	string generateBabName()
	{
		int nameIndex = rand() % babNames.size();
		return babNames.at(nameIndex);
	}

	void tierAdjustments()
	{
		if (tier == "Rotation  ")
		{
			int baseAdd = 2;
			int baseSub = 8;

			babdulishness = babdulishness -		(rand() % baseAdd - baseSub);
			shotClose = shotClose +				(rand() % baseAdd - baseSub);
			shot3 = shot3 +						(rand() % baseAdd - baseSub);
			shotMid = shotMid +					(rand() % baseAdd - baseSub);
			passAccuracy = passAccuracy +		(rand() % baseAdd - baseSub);
			perimeterD = perimeterD +			(rand() % baseAdd - baseSub);
			interiorD = interiorD +				(rand() % baseAdd - baseSub);
			shotContest = shotContest +			(rand() % baseAdd - baseSub);
			block = block +						(rand() % baseAdd - baseSub);
			defRebound = defRebound +			(rand() % baseAdd - baseSub);
			offRebound = offRebound +			(rand() % baseAdd - baseSub);
			speed = speed +						(rand() % baseAdd - baseSub);
			strength = strength +				(rand() % baseAdd - baseSub);
		}
		else if (tier == "Starter   ")
		{
			int baseAdd = 8;
			int baseSub = 2;

			babdulishness = babdulishness -		(rand() % baseAdd - baseSub);
			shotClose = shotClose +				(rand() % baseAdd - baseSub);
			shot3 = shot3 +						(rand() % baseAdd - baseSub);
			shotMid = shotMid +					(rand() % baseAdd - baseSub);
			passAccuracy = passAccuracy +		(rand() % baseAdd - baseSub);
			perimeterD = perimeterD +			(rand() % baseAdd - baseSub);
			interiorD = interiorD +				(rand() % baseAdd - baseSub);
			shotContest = shotContest +			(rand() % baseAdd - baseSub);
			block = block +						(rand() % baseAdd - baseSub);
			defRebound = defRebound +			(rand() % baseAdd - baseSub);
			offRebound = offRebound +			(rand() % baseAdd - baseSub);
			speed = speed +						(rand() % baseAdd - baseSub);
			strength = strength +				(rand() % baseAdd - baseSub);
		}
		else if (tier == "All-Star  ")
		{
			int baseAdd = 10;
			int floorRaise = 5;

			babdulishness = babdulishness -		(rand() % baseAdd + floorRaise);
			shotClose = shotClose +				(rand() % baseAdd + floorRaise);
			shot3 = shot3 +						(rand() % baseAdd + floorRaise);
			shotMid = shotMid +					(rand() % baseAdd + floorRaise);
			passAccuracy = passAccuracy +		(rand() % baseAdd + floorRaise);
			perimeterD = perimeterD +			(rand() % baseAdd + floorRaise);
			interiorD = interiorD +				(rand() % baseAdd + floorRaise);
			shotContest = shotContest +			(rand() % baseAdd + floorRaise);
			block = block +						(rand() % baseAdd + floorRaise);
			defRebound = defRebound +			(rand() % baseAdd + floorRaise);
			offRebound = offRebound +			(rand() % baseAdd + floorRaise);
			speed = speed +						(rand() % baseAdd + floorRaise);
			strength = strength +				(rand() % baseAdd + floorRaise);
		}
		else if (tier == "Superstar ")
		{
			int baseAdd = 15;
			int floorRaise = 8;

			babdulishness = babdulishness -		(rand() % baseAdd + floorRaise);
			shotClose = shotClose +				(rand() % baseAdd + floorRaise);
			shot3 = shot3 +						(rand() % baseAdd + floorRaise);
			shotMid = shotMid +					(rand() % baseAdd + floorRaise);
			passAccuracy = passAccuracy +		(rand() % baseAdd + floorRaise);
			perimeterD = perimeterD +			(rand() % baseAdd + floorRaise);
			interiorD = interiorD +				(rand() % baseAdd + floorRaise);
			shotContest = shotContest +			(rand() % baseAdd + floorRaise);
			block = block +						(rand() % baseAdd + floorRaise);
			defRebound = defRebound +			(rand() % baseAdd + floorRaise);
			offRebound = offRebound +			(rand() % baseAdd + floorRaise);
			speed = speed +						(rand() % baseAdd + floorRaise);
			strength = strength +				(rand() % baseAdd + floorRaise);
		}
		else
		{
			cout << "Invalid tier" << endl;
		}
	}

	void buildAdjustments()
	{
		if (this->build == "All_Around   ")
		{
			babdulishness		-= 5;
			shotClose			+= 8;
			shot3				+= 5;
			shotMid				+= 5;
			passAccuracy		+= 5;
			perimeterD			+= 2;
			interiorD			+= 2;
			shotContest			+= 5;
			block				+= 2;
			defRebound			+= 5;
			offRebound			+= 2;
			speed				+= 5;
			strength			+= 5;
		}
		else if (this->build == "Shooter      ")
		{
			babdulishness		-= 0;
			shotClose			+= 5;
			shot3				+= 10;
			shotMid				+= 10;
			passAccuracy		+= 0;
			perimeterD			-= 5;
			interiorD			-= 10;
			shotContest			-= 5;
			block				-= 10;
			defRebound			-= 5;
			offRebound			-= 5;
			speed				-= 2;
			strength			-= 10;
		}
		else if (this->build == "Playmaker    ")
		{
			babdulishness		-= 5;
			shotClose			+= 2;
			shot3				+= 2;
			shotMid				+= 8;
			passAccuracy		+= 10;
			perimeterD			+= 5;
			interiorD			-= 10;
			shotContest			+= 5;
			block				-= 10;
			defRebound			+= 0;
			offRebound			+= 0;
			speed				+= 10;
			strength			-= 8;
		}
		else if (this->build == "Defender     ")
		{
			babdulishness		-= 5;
			shotClose			+= 0;
			shot3				-= 10;
			shotMid				-= 8;
			passAccuracy		-= 5;
			perimeterD			+= 8;
			interiorD			+= 8;
			shotContest			+= 10;
			block				+= 5;
			defRebound			+= 5;
			offRebound			+= 0;
			speed				+= 2;
			strength			+= 5;
		}
		else if (this->build == "Slasher      ")
		{
			babdulishness		-= 0;
			shotClose			+= 10;
			shot3				-= 2;
			shotMid				+= 8;
			passAccuracy		+= 8;
			perimeterD			+= 8;
			interiorD			-= 5;
			shotContest			+= 8;
			block				+= 0;
			defRebound			+= 2;
			offRebound			+= 8;
			speed				+= 10;
			strength			+= 8;
		}
		else if (this->build == "Rebounder    ")
		{
			babdulishness		-= 0;
			shotClose			+= 8;
			shot3				-= 5;
			shotMid				+= 5;
			passAccuracy		-= 2;
			perimeterD			-= 8;
			interiorD			+= 5;
			shotContest			+= 2;
			block				+= 2;
			defRebound			+= 10;
			offRebound			+= 10;
			speed				+= 2;
			strength			+= 10;
		}
		else if (this->build == "Shot_Blocker ")
		{
			babdulishness		-= 0;
			shotClose			+= 2;
			shot3				-= 10;
			shotMid				-= 8;
			passAccuracy		-= 5;
			perimeterD			-= 5;
			interiorD			+= 10;
			shotContest			+= 10;
			block				+= 10;
			defRebound			+= 8;
			offRebound			+= 0;
			speed				-= 2;
			strength			+= 10;
		}
		else if (this->build == "Paint_Scorer ")
		{
			babdulishness		-= 2;
			shotClose			+= 10;
			shot3				-= 5;
			shotMid				+= 2;
			passAccuracy		+= 0;
			perimeterD			-= 10;
			interiorD			+= 2;
			shotContest			+= 0;
			block				+= 2;
			defRebound			+= 5;
			offRebound			+= 8;
			speed				-= 2;
			strength			+= 10;
		}
		else
		{
			cout << "Build not found" << endl;
		}
	}

	int generateShotClose(int height)
	{
		int base = height - 10;

		if (build == "Paint_Scorer " && base < 80)
			base += 10;

		int variation = rand() % 30 - 15;
		return (base + variation);
	}

	int generateShotMid(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 10;
		if (height < 78)
			base += 10;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 2;

		if (build == "Shooter      " && base < 80)
			base += 10;

		if (base < (shot3 - 10))
		{
			base = shot3 - 10;
		}

		int variation = rand() % 10 - 5;
		return base;
	}

	int generateShot3(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 10;
		if (height < 78)
			base += 10;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 8;

		if (build == "Shooter      " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generatePassAccuracy(int height)
	{
		int base = height - 12;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 8;
		if (height < 78)
			base += 8;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 5;

		if (build == "Playmaker    " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}
	
	int generateSpeed(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 8;
		if (height < 75)
			base += 8;
		if (height < 78)
			base += 8;
		if (height >= 80)
			base -= 5;
		if (height >= 82)
			base -= 12;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateStrength(int height)
	{
		int base = (weight / 5) - 10;
		if (height < 70)
			base -= 15;
		if (height < 75)
			base -= 5;
		if (height < 78)
			base += 5;
		if (height >= 80)
			base += 8;
		if (height >= 82)
			base += 10;

		if (build == "Defender     " && base < 80 && (position == "C " || position == "PF"))
			base += 10;
		
		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generatePerimeterD(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 2;
		if (height < 75)
			base += 5;
		if (height < 78)
			base += 8;
		if (height >= 80)
			base -= 5;
		if (height >= 82)
			base -= 8;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateInteriorD(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 30;
		if (height < 75)
			base -= 20;
		if (height < 78)
			base += 0;
		if (height >= 80)
			base += 8;
		if (height >= 82)
			base += 10;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateShotContest(int height)
	{
		int base = height - 15;
		if (height < 70)
			base -= 5;
		if (height < 75)
			base += 0;
		if (height < 78)
			base += 5;
		if (height >= 80)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateBlock(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 35;
		if (height < 75)
			base -= 25;
		if (height < 78)
			base -= 8;
		if (height >= 78)
			base -= 2;
		if (height >= 82)
			base -= 2;

		if (build == "Shot_Blocker " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateDefRebound(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 10;
		if (height < 75)
			base -= 5;
		if (height < 78)
			base += 2;
		if (height >= 78)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Rebounder    " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateOffRebound(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 25;
		if (height < 75)
			base -= 20;
		if (height < 78)
			base += 2;
		if (height >= 78)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Rebounder    " && base < 80)
			base += 10;

		int variation = rand() % 25 - 15;
		return (base + variation);
	}

	int generateBabdulishness()
	{
		int base = rand() % 50 + 25;
		return (base);
	}

	int heightInInches(pair<int,int> height)
	{
		// 5ft = 60 inches
		// 6ft = 72 inches
		// 7ft = 84 inches

		return ((height.first * 12) + height.second);
	}

	int calculateOverall(int babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength)
	{
		int overall = (
			((100 - babdulishness)	* 4) +
			(shotClose				* 3) +
			(shotMid				* 3) +
			(shot3					* 3) +

			(passAccuracy			* 2) +

			(perimeterD				* 2) +
			(interiorD				* 2) +
			(shotContest			* 4) +
			(block					* 2) +

			(defRebound				* 2) +
			(offRebound				* 1) +

			(speed					* 2) +
			(strength				* 2)
			) / 28;

		return overall;
	}

public:
	
	Babdul()
	{
		babName = generateBabName();
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		babdulishness = generateBabdulishness();

		shotClose = generateShotClose(heightInInches(height));
		shot3 = generateShot3(heightInInches(height));
		shotMid = generateShotMid(heightInInches(height));

		passAccuracy = generatePassAccuracy(heightInInches(height));

		perimeterD = generatePerimeterD(heightInInches(height));
		interiorD = generateInteriorD(heightInInches(height));
		shotContest = generateShotContest(heightInInches(height));
		block = generateBlock(heightInInches(height));

		defRebound = generateDefRebound(heightInInches(height));
		offRebound = generateOffRebound(heightInInches(height));

		speed = generateSpeed(heightInInches(height));
		strength = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(string babName)
	{
		this->babName = babName;
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		babdulishness = generateBabdulishness();

		shotClose = generateShotClose(heightInInches(height));
		shot3 = generateShot3(heightInInches(height));
		shotMid = generateShotMid(heightInInches(height));

		passAccuracy = generatePassAccuracy(heightInInches(height));

		perimeterD = generatePerimeterD(heightInInches(height));
		interiorD = generateInteriorD(heightInInches(height));
		shotContest = generateShotContest(heightInInches(height));
		block = generateBlock(heightInInches(height));

		defRebound = generateDefRebound(heightInInches(height));
		offRebound = generateOffRebound(heightInInches(height));

		speed = generateSpeed(heightInInches(height));
		strength = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(string babName, pair<int,int> height, int weight, string position, string tier, string build, float babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength)
	{
		this->babName = babName;
		age = rand() % 7 + 18;
		this->weight = weight;
		this->height = height;
		this->position = position;
		this->tier = tier;
		this->build = build;
		
		this->babdulishness = babdulishness;
		
		this->shotClose = shotClose;
		this->shot3 = shot3;
		this->shotMid = shotMid;
		
		this->passAccuracy = passAccuracy;

		this->perimeterD = perimeterD;
		this->interiorD = interiorD;
		this->shotContest = shotContest;
		this->block = block;

		this->defRebound = defRebound;
		this->offRebound = offRebound;

		this->speed = speed;
		this->strength = strength;

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(int nameIndex)
	{
		// Randomize Babnames
		auto rng = std::default_random_engine{};
		std::shuffle(std::begin(babNames), std::end(babNames), rng);

		babName = babNames.at(nameIndex);
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		babdulishness = generateBabdulishness();

		shotClose = generateShotClose(heightInInches(height));
		shot3 = generateShot3(heightInInches(height));
		shotMid = generateShotMid(heightInInches(height));

		passAccuracy = generatePassAccuracy(heightInInches(height));

		perimeterD = generatePerimeterD(heightInInches(height));
		interiorD = generateInteriorD(heightInInches(height));
		shotContest = generateShotContest(heightInInches(height));
		block = generateBlock(heightInInches(height));

		defRebound = generateDefRebound(heightInInches(height));
		offRebound = generateOffRebound(heightInInches(height));

		speed = generateSpeed(heightInInches(height));
		strength = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;

		statCorrect();
		resetSliders(1);
	}

	string getBabName() { return this->babName; }

	int getAge() { return this->age; }

	int getWeight() { return this->weight; }

	pair<int, int> getHeight() { return this->height; }
	int getHeightInInches() { return ((height.first * 12) + height.second);	}

	string getPosition() { return this->position; }

	string getTier() { return this->tier; }
	string getBuild() { return this->build; }

	void resetSliders(int sliderNum) { sliders.setSliders("Default", sliderNum); }

	float getBabdulishness() { return this->babdulishness; }
	
	int getShotClose() { return this->shotClose; }
	int getShotMid() { return this->shotMid; }
	int getShot3() { return this->shot3; }
	int getPassAccuracy() { return this->passAccuracy; }
	int getPerimeterD() { return this->perimeterD; }
	int getInteriorD() { return this->interiorD; }
	int getShotContest() { return this->shotContest; }
	int getBlock() { return this->block; }
	int getDefRebound() { return this->defRebound; }
	int getOffRebound() { return this->offRebound; }
	int getSpeed() { return this->speed; }
	int getStrength() { return this->strength; }

	int getOverall() { return this->overall; }

	int getPoints() { return this->points; }

	int getBlocks() { return this->blocks; }

	int getAssists() { return this->assists; }

	int getRebounds() { return this->rebounds; }

	void addPoints(int points) { this->points += points; }
	void setPoints(int points) { this->points = points; }

	void addBlock() { this->blocks += 1; }

	void addAssist() { this->assists += 1; }

	void addDefRebound() { this->rebounds += 1; }
	void addOffRebound() { this->rebounds += 1; }

	int getLocation() { return this->location; }
	void setLocation(int loc) { this->location = loc; }

	bool getBallCarrier() { return this->ballCarrier; }
	void setBallCarrier(bool bc) { this->ballCarrier = bc; }

	bool getWasPasser() { return this->wasPasser; }
	void setWasPasser(bool wp) { this->wasPasser = wp; }

	bool getIsRebounder() { return this->isRebounder; }
	void setIsRebounder(bool ir) { this->isRebounder = ir; }

	bool getIsInDraft() { return this->isInDraft; }
	void setIsInDraft(bool isInDraft) { this->isInDraft = isInDraft; }
	
	void printStats()
	{
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "Name:              " << getBabName() << endl;
		cout << "---------------------------" << endl;
		cout << "Tier:              " << getTier() << endl;
		cout << "Build:             " << getBuild() << endl;
		cout << "---------------------------" << endl;
		cout << "Overall:           " << getOverall() << endl
			<< endl;			    
		cout << "Babdulishness:     " << getBabdulishness() << endl 
			<< endl;			    
		cout << "Shot Close:        " << getShotClose() << endl;
		cout << "Shot Mid:          " << getShotMid() << endl;
		cout << "Shot 3:            " << getShot3() << endl
			<< endl;			    
		cout << "Passing Accuracy:  " << getPassAccuracy() << endl
			<< endl;
		cout << "Perimeter Defense: " << getPerimeterD() << endl;
		cout << "Interior Defense:  " << getInteriorD() << endl;
		cout << "Shot Contest:      " << getShotContest() << endl;
		cout << "Block:             " << getBlock() << endl
			<< endl;			    
		cout << "Defensive Rebound: " << getDefRebound() << endl;
		cout << "Offensive Rebound: " << getOffRebound() << endl
			<< endl;			    
		cout << "Speed:             " << getSpeed() << endl;
		cout << "Strength:          " << getStrength() << endl;
		cout << "---------------------------" << endl;
		cout << endl;
	}

	void statCorrect()
	{
		if (this->age > 99)
			this->age = 99;
		else if (this->age < 1)
			this->age = 1;

		if (this->weight > 999)
			this->weight = 999;
		else if (this->weight < 1)
			this->weight = 1;

		if (this->height.first > 9)
			this->height.first = 9;
		else if (this->height.first < 1)
			this->height.first = 1;

		if (this->height.second > 11)
			this->height.second = 11;
		else if (this->height.second < 0)
			this->height.second = 0;

		if (this->overall > 99)
			this->overall = 99;
		else if (this->overall < 25)
			this->overall = 25;
		
		if (this->babdulishness > 99)
			this->babdulishness = 99;
		else if (this->babdulishness < 10)
			this->babdulishness = 10;

		if (this->shotClose > 99)
			this->shotClose = 99;
		else if (this->shotClose < 10)
			this->shotClose = 10;

		if (this->shotMid > 99)
			this->shotMid = 99;
		else if (this->shotMid < 10)
			this->shotMid = 10;

		if (this->shot3 > 99)
			this->shot3 = 99;
		else if (this->shot3 < 10)
			this->shot3 = 10;

		if (this->passAccuracy > 99)
			this->passAccuracy = 99;
		else if (this->passAccuracy < 10)
			this->passAccuracy = 10;

		if (this->perimeterD > 99)
			this->perimeterD = 99;
		else if (this->perimeterD < 10)
			this->perimeterD = 10;

		if (this->interiorD > 99)
			this->interiorD = 99;
		else if (this->interiorD < 10)
			this->interiorD = 10;

		if (this->shotContest > 99)
			this->shotContest = 99;
		else if (this->shotContest < 10)
			this->shotContest = 10;

		if (this->block > 99)
			this->block = 99;
		else if (this->block < 10)
			this->block = 10;

		if (this->speed > 99)
			this->speed = 99;
		else if (this->speed < 10)
			this->speed = 10;

		if (this->defRebound > 99)
			this->defRebound = 99;
		else if (this->defRebound < 10)
			this->defRebound = 10;

		if (this->offRebound > 99)
			this->offRebound = 99;
		else if (this->offRebound < 10)
			this->offRebound = 10;

		if (this->strength > 99)
			this->strength = 99;
		else if (this->strength < 10)
			this->strength = 10;
	}

	bool shoot(Babdul& defender, int numPasses, int numDrives)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = ((babdulishness * sliders.slider_babdulishness) / (numPasses + 1)) - (numDrives * 5);
		int newSkill;

		if (location == 7)
			newSkill = ((shotClose * sliders.slider_shotClose) + (numPasses * 5) + (numDrives * 5));
		else if (location == 6)
			newSkill = ((shotMid * sliders.slider_shotMid) + (numPasses * 5) + (numDrives * 5));
		else if (location < 6)
			newSkill = ((shot3 * sliders.slider_shot3) + (numPasses * 5) + (numDrives * 5));

		newSkill -= ((defender.getShotContest() * defender.sliders.slider_shotContest) / 5);
		
		cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (newSkill + (defender.getShotContest() / 5) > success && success > newSkill)
			cout << "Defender's shot contest altered the shot" << endl;
		else if (success < newBabdulishness)
			cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			cout << "Insufficient shooting skill" << endl;

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool pass(Babdul& defender, int numPasses, int numDrives)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (((babdulishness * sliders.slider_babdulishness) / 4) / (numPasses + 1));
		int newSkill = ((passAccuracy * sliders.slider_passAccuracy) + (numPasses * 5) + (numDrives * 5));

		cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			cout << "Insufficient passing accuracy" << endl;

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool drive(Babdul& defender, int numPasses, int numDrives)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (((babdulishness * sliders.slider_babdulishness) / 3) / (numPasses + 1));
		int newSkill = ((speed * sliders.slider_speed) + (numPasses * 5) + (numDrives * 5));

		cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			cout << "Insufficient speed" << endl;
		else if (speed < (defender.getPerimeterD() - (numPasses + (numDrives * 2))))
			cout << "The defender's perimeter D prevented the drive and forced a turnover" << endl;

		if (success > newBabdulishness && success < newSkill && speed >= ((defender.getPerimeterD() * defender.sliders.slider_perimeterD) - (numPasses + (numDrives * 2))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool backDown(Babdul& defender)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (babdulishness * sliders.slider_babdulishness);
		int newSkill = (strength * sliders.slider_strength);

		int variation = rand() % 10 - 5;
		int defenderInteriorD = (defender.getInteriorD() * defender.sliders.slider_interiorD) + variation - 10;

		cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			cout << "Insufficient strength" << endl;
		else if (strength < defenderInteriorD)
			cout << "The defender's interior D prevented the back down attempt and forced a turnover" << endl;

		if (success > newBabdulishness && success < newSkill && (strength * sliders.slider_strength) > defenderInteriorD)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool attemptBlock()
	{
		int success = rand() % 100 + 1;
				
		if (success > (babdulishness * sliders.slider_babdulishness) && success < ((block * sliders.slider_block) - 20))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool attemptDefRebound()
	{
		int success = rand() % 100 + 1;

		if (success > (babdulishness * sliders.slider_babdulishness) && success < ((defRebound * sliders.slider_defRebound) - 20))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool attemptOffRebound()
	{
		int success = rand() % 100 + 1;

		if (success > (babdulishness * sliders.slider_babdulishness) && success < ((offRebound * sliders.slider_offRebound) - 25))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool compareBabName(const Babdul& b1, const Babdul& b2)
{
	return b1.babName < b2.babName;
}

bool compareAge(const Babdul& b1, const Babdul& b2)
{
	return b1.age < b2.age;
}

bool compareWeight(const Babdul& b1, const Babdul& b2)
{
	return b1.weight < b2.weight;
}

bool compareHeight(const Babdul& b1, const Babdul& b2)
{
	if (b1.height.first == b2.height.first)
		return b1.height.second > b2.height.second;
	else
		return b1.height.first > b2.height.first;
}

bool comparePosition(const Babdul& b1, const Babdul& b2)
{
	return b1.position < b2.position;
}

bool compareTier(const Babdul& b1, const Babdul& b2)
{
	return b1.tier < b2.tier;
}

bool compareBuild(const Babdul& b1, const Babdul& b2)
{
	return b1.build < b2.build;
}

bool compareBabdulishness(const Babdul& b1, const Babdul& b2)
{
	return b1.babdulishness < b2.babdulishness;
}

bool compareOverall(const Babdul& b1, const Babdul& b2)
{
	return b1.overall > b2.overall;
}

bool comparePoints(const Babdul& b1, const Babdul& b2)
{
	return b1.points > b2.points;
}

bool compareBlocks(const Babdul& b1, const Babdul& b2)
{
	return b1.blocks > b2.blocks;
}

bool compareAssists(const Babdul& b1, const Babdul& b2)
{
	return b1.assists > b2.assists;
}

bool compareShotClose(const Babdul& b1, const Babdul& b2)
{
	return b1.shotClose > b2.shotClose;
}

bool compareShotMid(const Babdul& b1, const Babdul& b2)
{
	return b1.shotMid > b2.shotMid;
}

bool compareShot3(const Babdul& b1, const Babdul& b2)
{
	return b1.shot3 > b2.shot3;
}

bool comparePassAcc(const Babdul& b1, const Babdul& b2)
{
	return b1.passAccuracy > b2.passAccuracy;
}

bool comparePerimeterD(const Babdul& b1, const Babdul& b2)
{
	return b1.perimeterD > b2.perimeterD;
}

bool compareInteriorD(const Babdul& b1, const Babdul& b2)
{
	return b1.interiorD > b2.interiorD;
}

bool compareShotContest(const Babdul& b1, const Babdul& b2)
{
	return b1.shotContest > b2.shotContest;
}

bool compareBlock(const Babdul& b1, const Babdul& b2)
{
	return b1.block > b2.block;
}

bool compareDefRebound(const Babdul& b1, const Babdul& b2)
{
	return b1.defRebound > b2.defRebound;
}

bool compareOffRebound(const Babdul& b1, const Babdul& b2)
{
	return b1.offRebound > b2.offRebound;
}

bool compareSpeed(const Babdul& b1, const Babdul& b2)
{
	return b1.speed > b2.speed;
}

bool compareStrength(const Babdul& b1, const Babdul& b2)
{
	return b1.strength > b2.strength;
}