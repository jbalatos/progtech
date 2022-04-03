#include "player.hpp"

class RighteousPlayer : public Player {
	public:
		RighteousPlayer (const std::string& n) : Player(n) {}
		const std::string& getType () const { return type; }

		Move play (const State& s) {
			int max_coins = -1, max_source = -1;
			for (int i=0; i<s.getHeaps(); ++i) if (max_coins < s.getCoins(i))
				max_coins = s.getCoins(i), max_source = i;

			int min_coins = s.getCoins(0), min_source = 0;
			for (int i=1; i<s.getHeaps(); ++i) if (min_coins > s.getCoins(i))
				min_coins = s.getCoins(i), min_source = i;

			max_coins = (max_coins + 1) / 2;
			return Move(max_source, max_coins, min_source, max_coins - 1);
		}
	private:
		std::string type = "Righteous";
};
