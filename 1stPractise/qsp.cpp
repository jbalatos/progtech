#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main () {

#ifndef CONTEST
	freopen("qsp.in", "r", stdin);
#endif //CONTEST

	int n;
	cin >> n;
	deque<int> q;
	stack<int> s;

	for (int i=n; i-->0;) {
		int x;
		cin >> x;
		q.push_back(x);
	}

	char ch;
	while (cin >> ch) {
		if ( (ch == 'Q' && q.empty()) || (ch == 'S' && s.empty()) ) {
			cout << "error\n";
			break;
		}

		if (ch == 'Q') {
			s.push( q.front() ), q.pop_front();
		} else if (ch == 'S') {
			q.push_back( s.top() ), s.pop();
		} else { // ch == 'P'
			for (auto it : q)
				cout << (it == q.front() ? "" : " ") << it;
			cout << '\n';
		}
	}

	return 0;
}

