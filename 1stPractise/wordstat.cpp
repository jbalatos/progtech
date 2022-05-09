#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

class data {/*{{{*/
	private:
		int wordcount;
		set<string> wordset;
		string longest, shortest;

		int get_words () { return wordcount; }
		int get_unique_words () { return wordset.size(); }

		string get_longest () { return longest; }
		string get_shortest () { return shortest; }

		void set_longest (const string& str) {
			if (longest == "" || str.size() > longest.size() ||
			    ( str.size() == longest.size() && str < longest ))
				longest = str;
		}

		void set_shortest (const string& str) {
			if (shortest == "" || str.size() < shortest.size() ||
			    ( str.size() == shortest.size() && str < shortest ))
				shortest = str;
		}

	public:
		data () : wordcount(0), wordset(), longest(""), shortest("") {}

		data& operator += (const string& str) {
			wordcount++, wordset.insert(str);
			set_longest(str), set_shortest(str);
			return *this;
		}

		friend ostream& operator<< (ostream& out, data& d) {
			if (d.get_words() == 0) return out;

			out << d.get_words() << " word(s), " << d.get_unique_words()
			    << " unique word(s), longest '" << d.get_longest() << "' and shortest '"
			    << d.get_shortest() << "'";

			return out;

		}
};/*}}}*/

int main () {

#ifndef CONTEST
	freopen("wordstat.in", "r", stdin);
#endif //CONTEST

	map<char, data> m;

	string str;
	while (cin >> str) {
		m[ str[0] ] += str;
	}

	for (auto it : m) cout << it.first << ": " << it.second << '\n';

	return 0;
}

