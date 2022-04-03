#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include "player.hpp"

class Game {
	public:
		Game (int heaps, int players);
		~Game ();

		void addHeap (int coins);
		void addPlayer (Player *player);
		void play (std::ostream& out);

		int getPlayers () const;
		const Player* getPlayer (int p) const;

	private:
		int heaps, players, heap_to_add, player_to_add;
		int *coins;
		Player **pool;
};

#endif //_GAME_HPP_
