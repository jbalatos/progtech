#include <iostream>
#include <stdexcept>
#include <string>
#include <climits>

#ifndef CONTEST
#define SPECKER_V2
#include "specker1n.cpp"
#endif

class Player {/*{{{*/
	public:
		Player (const std::string &n);
		virtual ~Player ();

		virtual const std::string& getType () const = 0;
		virtual Move play (const State& s) = 0;

		friend std::ostream& operator<< (std::ostream& out, const Player& player);
};/*}}}*/

#ifndef SPECKER_V3
#ifndef CONTEST
int main () {}
#endif
#endif
