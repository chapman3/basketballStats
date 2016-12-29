#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "player.hpp"
#include "menu.hpp"

using namespace std;


int main(int argc, char *argv[]){
	
	//setup
	Menu menu;
	vector<Player> gameStats;
	char inputType;
	inputType = menu.displayWelcomeMenu();

	//initialize vector
	

	if(inputType=='d'){//read from data file
		int totalPlayers;
		int tempNum, tempPts, tempRbds, tempAsts;
		string tempName;
		ifstream fileStream("input.txt");
		fileStream >> totalPlayers;
		for(int i=0; i<totalPlayers; i++){
			tempNum = i+1;
			fileStream >> tempName;
			fileStream >> tempPts;
			fileStream >> tempAsts;
			fileStream >> tempRbds;
			gameStats.push_back(Player(tempNum, tempName, tempPts, tempRbds, tempAsts));
		}
	}
	else if(inputType=='k'){//read from stdin
		int totalPlayers;
		int tempNum, tempPts, tempRbds, tempAsts;
		string tempName;
		bool cond;
		cout<< "Number of players? :";
		cin>> totalPlayers;
		tempNum = 1;

		for(int i=0; i<totalPlayers; i++){
			//loop to add player's stats to vector
			cout<< "Player " << tempNum << " Name? :";
			cin>> tempName;
			do{
				cout<< "Player " << tempNum << "'s Points? (must be an integer):";
				cin>> tempPts;
				cond = cin.fail();
			    cin.clear();
			    cin.ignore(1000, '\n');
			}while(cond);
			do{
				cout<< "Player " << tempNum << "'s Assists? (must be an integer):";
				cin>> tempAsts;
				cond = cin.fail();
				cin.clear();
				cin.ignore(1000, '\n');
			}while(cond);
			do{
				cout<< "Player " << tempNum << "'s Rebounds? (must be an integer):";
				cin>> tempRbds;
				cond = cin.fail();
				cin.clear();
				cin.ignore(1000, '\n');
			}while(cond);
			gameStats.push_back(Player(tempNum, tempName, tempPts, tempRbds, tempAsts));
			tempNum++;
		}
	}

	//debugging help: print vector contents to check
	/*vector<Player>::iterator it = gameStats.begin();
	for(it; it != gameStats.end(); ++it) {
		Player temp = *it;
		cout << "NAME: " << temp.name << "  POINTS: " << temp.points << "  REBOUNDS: "
		<< temp.rebounds << "  Assists: " << temp.assists << endl;
	}*/

	menu.displayMainMenu(gameStats);

	return 0;

}
