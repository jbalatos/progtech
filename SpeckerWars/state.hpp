#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <iostream>
#include "move.hpp"

class State {
	public:
		State (int h, const int c[], int n);
		~State ();

		void next (const Move& move);
		bool winning () const;

		int getHeaps () const;
		int getCoins (int h) const;

		int getPlayers () const;
		int getPlaying () const;

		friend std::ostream& operator<< (std::ostream& out, const State& state);

	private:
		int heaps, players, *coins;
		int current_player;
};

#endif //_STATE_HPP_
