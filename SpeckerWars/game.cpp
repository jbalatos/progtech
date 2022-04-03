#include "game.hpp"

#include <stdexcept>
#include "move.hpp"
#include "state.hpp"
#include "player.hpp"

Game::Game (int heaps, int players)
	: heaps(heaps), players(players),
	  heap_to_add(0), player_to_add(0),
	  coins(new int[heaps]), pool (new Player*[players])
{}

Game::~Game () {
	delete[] coins;
	for (int i=0; i<players; ++i) delete pool[i];
	delete[] pool;
}

void Game::addHeap (int x) {
	if (x < 0) throw std::logic_error("Invalid coins for heap " + heap_to_add);
	if (heap_to_add == heaps) throw std::logic_error("Too many heaps added");
	coins[heap_to_add++] = x;
}

void Game::addPlayer (Player *p) {
	if (!p) throw std::logic_error("Invalid player given to add");
	if (player_to_add == players) throw std::logic_error("Too many players added");
	pool[player_to_add++] = p;
}

const Player* Game::getPlayer (int p) const {
	if (p < 0 || p >= players) throw std::logic_error("Invalid player index");
	return pool[p];
}

int Game::getPlayers () const { return players; }

void Game::play (std::ostream& out) {
	try {
		if (heap_to_add != heaps)
			throw std::logic_error("Too few heaps added");
		if (player_to_add != players)
			throw std::logic_error("Too few players added");

		State state(heaps, coins, players);

		while (!state.winning()) {
			out << "State: " << state << "\n";
			Player* current = pool[ state.getPlaying() ];
			Move move = current->play(state);
			out << *current << ' ' << move << "\n";
			state.next(move);
		}

		int winner = state.getPlaying() - 1 + players;
		winner %= players;

		out << "State: " << state << "\n" << *pool[winner] << " wins\n";
	} catch (std::logic_error &e) {
		out << e.what();
	}
}
