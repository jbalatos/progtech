#ifndef CONTEST
#define SPECKER_V3
#include "specker_v2.cpp"
#endif

class Game {/*{{{*/
	public:
		Game (int heaps, int players);
		~Game ();

		void addHeap (int coins);
		void addPlayer (Player *player);
		void play (std::ostream& out);

		int getPlayers () const;
		const Player* getPlayer (int p) const;
};/*}}}*/

#ifndef CONTEST
int main () {/*{{{*/
	Game specker(3, 4);
	specker.addHeap(10);
	specker.addHeap(20);
	specker.addHeap(17);
	specker.addPlayer(new SneakyPlayer("Tom"));
	specker.addPlayer(new SpartanPlayer("Mary"));
	specker.addPlayer(new GreedyPlayer("Alan"));
	specker.addPlayer(new RighteousPlayer("Robin"));
	specker.play(std::cout);
}/*}}}*/
#endif
