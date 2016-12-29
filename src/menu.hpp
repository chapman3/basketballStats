#ifndef MENU_HPP_
#define MENU_HPP_

#include <vector>
#include <algorithm>
#include <iostream>
#include "player.hpp"

using namespace std;

class Menu{
public:
	Menu();
	static bool sortPointsHelpA(const Player&, const Player&);
	static bool sortPointsHelpD(const Player&, const Player&);
	static bool sortReboundsHelpA(const Player&, const Player&);
	static bool sortReboundsHelpD(const Player&, const Player&);
	static bool sortAssistsHelpA(const Player&, const Player&);
	static bool sortAssistsHelpD(const Player&, const Player&);
	static bool sortNamesHelpA(const Player&, const Player&);
	static bool sortNamesHelpD(const Player&, const Player&);
	static void doublesHelp(const Player&);
	void handleMenuFlow(int, char, vector<Player>&);
	char displayWelcomeMenu();
	void displayMainMenu(vector<Player>&);
	void displaySortMenu(vector<Player>&);
	void displayAvailOptionMenu(vector<Player>&);
	char displaySortOptionMenu();
	void displayVectorByName(vector<Player>&);
	void displayVectorByInt(char,vector<Player>&);
	void displayStats(vector<Player>&);
	void displayDoubles(vector<Player>&);
	int exitProgram();
};
#endif
