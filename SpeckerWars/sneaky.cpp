#include "player.hpp"
#include <climits>

class SneakyPlayer : public Player {
	public:
		SneakyPlayer (const std::string& n) : Player(n) {}
		const std::string& getType () const { return type; }

		Move play (const State& s) {
			int min_coins = INT_MAX, source = -1;
			for (int i=0; i<s.getHeaps(); ++i) if (s.getCoins(i) && min_coins > s.getCoins(i))
				min_coins = s.getCoins(i), source = i;

			return Move(source, min_coins, 0, 0);
		}
	private:
		std::string type = "Sneaky";
};
