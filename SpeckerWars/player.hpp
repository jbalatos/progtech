#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include "state.hpp"

class Player {
	public:
		Player (const std::string &n);
		virtual ~Player ();

		virtual const std::string& getType () const = 0;
		virtual Move play (const State& s) = 0;

		friend std::ostream& operator<< (std::ostream& out, const Player& player);

	private:
		std::string name;
};

#endif //_PLAYER_HPP_
