#include "state.hpp"

#include <stdexcept>
#include "move.hpp"

State::State (int h, const int c[], int n)
	: heaps(h), players(n), current_player(0)
{
	coins = new int[heaps];
	for (int i=0; i<heaps; ++i) coins[i] = c[i];
}

State::~State () {
	delete[] coins;
}

void State::next (const Move& move) {
	int s = move.getSource(), t = move.getTarget(),
	    sc = move.getSourceCoins(), tc = move.getTargetCoins();

	if (s < 0 || s >= heaps)
		throw std::logic_error("Invalid source heap");
	if (t < 0 || t >= heaps)
		throw std::logic_error("Invalid target heap");

	if (sc <= 0 || sc > coins[ move.getSource() ])
		throw std::logic_error("Invalid coin number chosen from souce");
	if (tc < 0 || sc <= tc)
		throw std::logic_error("Invalid coin number chosen to place");

	coins[s] -= sc, coins[t] += tc;
	current_player = (current_player + 1) % players;
}

bool State::winning () const {
	for (int i=0; i<heaps; ++i) if (coins[i]) return false;
	return true;
}

int State::getHeaps () const { return heaps; }

int State::getCoins (int h) const {
	if (h < 0 || h >= heaps) throw std::logic_error("Invalid heap");
	return coins[h];
}

int State::getPlayers () const { return players; }

int State::getPlaying () const { return current_player; }

std::ostream& operator<< (std::ostream& out, const State& state) {
	for (int i=0; i<state.heaps; ++i)
		out << state.coins[i] << ( i == state.heaps-1 ? " " : ", " );
	out << "with " << state.current_player << "/" << state.players
	    << " playing next";

	return out;
}
