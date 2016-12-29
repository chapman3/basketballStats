
#include <string>
#include "player.hpp"


Player::Player(int num, std::string lastName, int pts, int asts, int rbnds ){

	playerNum = num;					//Player Number
	name = lastName;					//Player's Last Name
	points = pts;						//Game Points
	assists = asts;						//Game Assists
	rebounds = rbnds;					//Game Rebounds
}
