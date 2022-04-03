#include "player.hpp"

Player::Player (const std::string &n) : name(n) {} 

Player::~Player () {}

std::ostream& operator<< (std::ostream& out, const Player& player) {
	out << player.getType() << " player " << player.name;
	return out;
}
