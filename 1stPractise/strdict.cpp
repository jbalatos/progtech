#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main () {

#ifndef CONTEST
	freopen("strdict.in", "r", stdin);
#endif

	int n, d;
	cin >> n >> d;
	map<string, int> m;
	set<string> s[d+1];

	while (n--) {
		int idx;
		string str;
		cin >> idx >> str;

		if ( s[idx].count(str) ) continue;

		s[idx].insert(str);
		if ( m.find(str) == m.end() )
			m[str] = 1;
		else
			++m[str];
	}

	// compute largest dict
	int res = -1;
	unsigned long long tmp = 0;
	for (int i=1; i<=d; ++i) if (tmp < s[i].size())
		res = i, tmp = s[i].size();

	cout << "largest dictionary is " << res << " with " << s[res].size() << " word(s)\n";

	// output all words
	res = 0;
	for (auto it : m) if (it.second == d) {
		res++;
		cout << it.first << '\n';
	}
	cout << res << " word(s) appear in all dictionaries\n";

	return 0;
}

