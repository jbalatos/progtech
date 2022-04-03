#include "player.hpp"

class SpartanPlayer : public Player {
	public:
		SpartanPlayer (const std::string& n) : Player(n) {}
		const std::string& getType () const { return type; }

		Move play (const State& s) {
			int max_coins = -1, source = -1;
			for (int i=0; i<s.getHeaps(); ++i) if (max_coins < s.getCoins(i))
				max_coins = s.getCoins(i), source = i;

			return Move(source, 1, 0, 0);
		}
	private:
		std::string type = "Spartan";
};
