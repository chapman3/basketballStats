#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <string>


class Player {

public:
	Player(int, std::string, int, int, int);
	int playerNum;			//Player Number
	std::string name;		//Player's Last Name
	int points;				//Game Points
	int assists;			//Game Assists
	int rebounds;			//Game Rebounds
};
#endif
