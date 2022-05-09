#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <string>
#include <map>

#define x first
#define y second
#define ITER(x) x.begin(), x.end()

using namespace std;

int main () {
#ifndef CONTEST
	freopen("energy.in", "r", stdin);
#endif //CONTEST

	// O( n )
	int n; cin >> n;
	vector<pair<string, int> > time;
	for (int i=n; i-->0;) {
		string str; int a;
		cin >> str >> a;
		time.push_back({ str, a });
	}

	// O( klogn )
	int k; cin >> k;
	map<string, vector<pair<int, int> > > offer;
	for (int i=k; i-->0;) {
		string str; int a, b;
		cin >> str >> a >> b;
		offer[str].push_back({ b, a });
	}

	// sort offers and times
	// O( nlogn + klogk )
	sort( ITER(time) );
	for (auto& it : offer) sort( ITER(it.y) );

	// O( n+klogk )
	for (const auto& it : time) {
		int hours = it.y, cost = 0;
		for (const auto& jt : offer[it.x]) {
			cost += jt.x * min(hours, jt.y);
			hours -= min(hours, jt.y);
			if (!hours) break;
		}
		if (hours) cout << "IMPOSSIBLE\n";
		else cout << it.x << ' ' << cost << '\n';
	}

	return 0;
}

