#include "game.hpp"
#include "righteous.cpp"
#include "greedy.cpp"
#include "spartan.cpp"
#include "sneaky.cpp"

int main () {
	Game specker(3, 4);
	specker.addHeap(10);
	specker.addHeap(20);
	specker.addHeap(17);
	specker.addPlayer(new SneakyPlayer("Tom"));
	specker.addPlayer(new SpartanPlayer("Mary"));
	specker.addPlayer(new GreedyPlayer("Alan"));
	specker.addPlayer(new RighteousPlayer("Robin"));
	specker.play(std::cout);
}
