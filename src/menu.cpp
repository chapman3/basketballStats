#include "player.hpp"
#include "menu.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Menu::Menu(){}
//sort algorithm predicate functions
bool Menu::sortPointsHelpA(const Player& player1, const Player& player2){
	return(player1.points<player2.points);
}
bool Menu::sortPointsHelpD(const Player& player1, const Player& player2){
	return(player1.points>player2.points);
}


bool Menu::sortReboundsHelpA(const Player& player1, const Player& player2){
	return(player1.rebounds<player2.rebounds);
}
bool Menu::sortReboundsHelpD(const Player& player1, const Player& player2){
	return(player1.rebounds>player2.rebounds);
}


bool Menu::sortAssistsHelpA(const Player& player1, const Player& player2){
	return(player1.assists<player2.assists);
}
bool Menu::sortAssistsHelpD(const Player& player1, const Player& player2){
	return(player1.assists>player2.assists);
}

bool Menu::sortNamesHelpA(const Player& player1, const Player& player2){
	return(player1.name<player2.name);
}
bool Menu::sortNamesHelpD(const Player& player1, const Player& player2){
	return(player1.name>player2.name);
}

void Menu::doublesHelp(const Player& player){//doubles display predicate function
	int doubCount = 0;
	if(player.points>9)
		doubCount+=1;
	if(player.assists>9)
		doubCount+=1;
	if(player.rebounds>9)
		doubCount+=1;
	if(doubCount>1){
		cout << "NAME: " << player.name << "  POINTS: " << player.points << "  REBOUNDS: "
			<< player.rebounds << "  Assists: " << player.assists << endl;
	}
}

void Menu::handleMenuFlow(int menu, char entry, vector<Player> &gameStats){
	
		switch(menu){
		case 0: //called from main menu or available options menu
			if(entry=='s'||entry=='d'||entry=='t'||entry=='e' ){
			switch(entry){
				case 's' :
					displaySortMenu(gameStats);
					break;
				case 'd' :
					displayStats(gameStats);
					break;
				case 't' :
					displayDoubles(gameStats);
					break;
				case 'e' :
					exitProgram();
					break;
				}
			}
			else{
			//error handle
			cout << "Sorry, that's not an available option!" << endl;
			displayMainMenu(gameStats);
			}
			break;
		case 1: //called from sort menu
			if(entry=='n'||entry=='p'||entry=='r'||entry=='a' ){
			switch(entry){
				case 'n' :
					displayVectorByName(gameStats);
					break;
				case 'p' :
					displayVectorByInt(entry, gameStats);
					break;
				case 'r' :
					displayVectorByInt(entry, gameStats);
					break;
				case 'a' :
					displayVectorByInt(entry, gameStats);
					break;
				}
			}
			else{
			//error handle
			cout << "Sorry, that's not an available option!" << endl;
			displaySortMenu(gameStats);
			}
			break;
		}
}

char Menu::displayWelcomeMenu(){
	char command;
	cout << "Welcome to the basketball program!" << endl;
	cout << "How do you want to retrieve player information?" << endl;
	cout << "Enter 'd' to read data from a data file" << endl;
	cout << "Enter 'k' to enter data via the keyboard." << endl;
	cout << "Enter your choice here:" << endl;
	cin >> command;
	return command;
}

void Menu::displayMainMenu(vector<Player> &gameStats){
	char command;
	cout << "******* MAIN MENU *******" << endl;
	cout << "'s' = sort and print player data" << endl;
	cout << "'d' = display player data" << endl;
	cout << "'t' = display triple-doubles and double-doubles" << endl;
	cout << "'e' = exit" << endl;
	cout << "Enter command: " << endl;
	cin >> command;
	handleMenuFlow(0, command, gameStats);
}

void Menu::displaySortMenu(vector<Player> &gameStats){
	char command;
	cout << "******* SORT MENU *******" << endl;
	cout << "'n' = sort alphabetically by name" << endl;
	cout << "'p' = sort numerically by points" << endl;
	cout << "'r' = sort numerically by rebounds" << endl;
	cout << "'a' = sort numerically by assists" << endl;
	cout << "Enter sort category:" << endl;
	cin >> command;
	handleMenuFlow(1, command, gameStats);
}

void Menu::displayAvailOptionMenu(vector<Player> &gameStats){
	char command;
	cout << "Available commands are:" << endl;
	cout << "'s' = sort and print player data" << endl;
	cout << "'t' = print triple-doubles and double-doubles" << endl;
	cout << "'d' = print player data" << endl;
	cout << "'e' = exit" << endl;
	cout << "Enter command:" << endl;
	cin >> command;
	handleMenuFlow(0, command, gameStats);
}

char Menu::displaySortOptionMenu(){
	char command;
	cout << "Available sorting orders are:" << endl;
	cout << "'a' = ascending order" << endl;
	cout << "'d' = descending order" << endl;
	cout << "Enter sort order:" << endl;
	cin >> command;
	return command;
}

void Menu::displayVectorByName(vector<Player> &gameStats){
	int order = displaySortOptionMenu();
	if(order=='a'||order=='d'){
		switch(order){
			case 'a':
				sort(gameStats.begin(),gameStats.end(), Menu::sortNamesHelpA);
				break;
			case 'd':
				sort(gameStats.begin(),gameStats.end(), Menu::sortNamesHelpD);
				break;
		}
		displayStats(gameStats);
	}
	else{
		cout << "Sorry, that's not an available option!" << endl;
		displaySortMenu(gameStats);
	}
}

void Menu::displayVectorByInt(char entry, vector<Player> &gameStats){
	int order = displaySortOptionMenu();
	if(order=='a'||order=='d'){
	switch(order){
	case 'a':
		switch(entry){
			case 'p':
				sort(gameStats.begin(),gameStats.end(), Menu::sortPointsHelpA);
				break;
			case 'r':
				sort(gameStats.begin(),gameStats.end(), Menu::sortReboundsHelpA);
				break;
			case 'a':
				sort(gameStats.begin(),gameStats.end(), Menu::sortAssistsHelpA);
				break;
			case 'n':
				break;
		}
		break;
	case 'd':
		switch(entry){
			case 'p':
				sort(gameStats.begin(),gameStats.end(), Menu::sortPointsHelpD);
				break;
			case 'r':
				sort(gameStats.begin(),gameStats.end(), Menu::sortReboundsHelpD);
				break;
			case 'a':
				sort(gameStats.begin(),gameStats.end(), Menu::sortAssistsHelpD);
				break;
			case 'n':
				break;
		}
		break;
	}
	displayStats(gameStats);
	}
	else{
		cout << "Sorry, that's not an available option!" << endl;
		displaySortMenu(gameStats);
	}
}

void Menu::displayStats(vector<Player> &gameStats){
	vector<Player>::iterator it = gameStats.begin();
		for(it; it != gameStats.end(); ++it) {
			Player temp = *it;
			cout << "NAME: " << temp.name << "  POINTS: " << temp.points << "  REBOUNDS: "
			<< temp.rebounds << "  Assists: " << temp.assists << endl;
		}
	displayMainMenu(gameStats);
}

void Menu::displayDoubles(vector<Player> &gameStats){
	//display all double doubles and triple doubles by player name.
	for_each(gameStats.begin(), gameStats.end(), Menu::doublesHelp);
	displayMainMenu(gameStats);
}
int Menu::exitProgram(){
	return 0;
}
