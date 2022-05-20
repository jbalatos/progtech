#include <iostream>
#include <string>

using namespace std;

class lexicon {
	public:
		lexicon ();
		~lexicon ();

		void insert (const string &s) noexcept;
		int lookup (const string &s) const noexcept;
		int depth (const string &s) const noexcept;
		void replace (const string &s1, const string &s2) noexcept;

		firend ostream& operator << (ostream &out, const lexicon &l) noexcept;
};

#ifndef CONTEST
int main () {
	lexicon l;
	l.insert("the");
	l.insert("boy");
	l.insert("and");
	l.insert("the");
	l.insert("wolf");
	cout << "The word 'the' is found " << l.lookup("the") << " time(s)" << endl;
	cout << "The word 'and' is found at depth " << l.depth("and") << endl;
	cout << l;
	l.replace("boy", "wolf");
	cout << "After replacement:\n";
	cout << l;
	cout << "Now the word 'and' is found at depth " << l.depth("and") << endl;

	return 0;
}
#endif // CONTEST

