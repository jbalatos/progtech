#ifndef _MOVE_HPP_
#define _MOVE_HPP_

#include <iostream>

class Move {
	public:
		Move (int sh, int sc, int th, int tc);

		int getSource () const;
		int getSourceCoins () const;
		int getTarget () const;
		int getTargetCoins () const;

		friend std::ostream& operator<< (std::ostream &out, const Move& move);

	private:
		int source, sourceCoins, target, targetCoins;
};

#endif // _MOVE_HPP_
