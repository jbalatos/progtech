#include <iostream>
#include <stdexcept>
#include <string>

class Move {/*{{{*/
	public:
		Move (int sh, int sc, int th, int tc);

		int getSource () const;
		int getSourceCoins () const;
		int getTarget () const;
		int getTargetCoins () const;

		friend std::ostream& operator<< (std::ostream &out, const Move& move);
};/*}}}*/

class State {/*{{{*/
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
};/*}}}*/

#ifndef SPECKER_V2
#ifndef CONTEST
int main () {}
#endif
#endif
