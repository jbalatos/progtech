#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

double distance (pair<double, double> a, pair<double, double> b) {
	return sqrt( pow(a.first - b.first, 2) +
	             pow(a.second - b.second, 2) );
}

int main () {

#ifndef CONTEST
	freopen("poi.in", "r", stdin);
#endif //CONTEST

	int n; cin >> n;
	map<string, vector<pair<double, double> > > m;
	string str;  int x, y;
	for (int i=n; i-->0;) {
		cin >> x >> y >> str;
		m[str].push_back({ x, y });
	}

	cin >> n;
	for (int i=n; i-->0;) {
		cin >> x >> y;

		cout << x << ' ' << y << '\n';
		for (auto it : m) {
			double res = numeric_limits<double>::max();
			for (auto jt : it.second) res = min( res, distance({x,y}, jt) );
			cout << "  " << it.first << ' ' << fixed << setprecision(3) << res << '\n';
		}
	}

	return 0;
}

