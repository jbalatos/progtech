#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

struct document {/*{{{*/
	int id;
	string first, last, name, reverse;
	int year, salary;

	document (int id=0, string first="", string last="", int year=0, int salary=0)
	: id(id), first(first), last(last), year(year), salary(salary) {
		name = first + " " + last;
		reverse = last + " " + first;
	}
};

ostream& operator << (ostream& out, const document& a) {
	out << a.id << ' ' << a.name << ' ' << a.year << ' ' << a.salary;
	return out;
}
/*}}}*/

int main () {

#ifndef CONTEST
	freopen("database.in", "r", stdin);
#endif //CONTEST

	int n; cin >> n;

	map<int, set<int> > id_map, year_map, salary_map;
	map<string, set<int> > name_map;
	map<int, document> db;

	for (int i=n; i-->0;) {
		int id, year, salary;
		string first, last;
		cin >> id >> first >> last >> year >> salary;

		db[id] = document(id, first, last, year, salary);

		id_map[id].insert(id);
		name_map[ db[id].reverse ].insert(id);
		year_map[year].insert(id);
		salary_map[salary].insert(id);
	}

	int m; cin >> m;
	for (int i=m; i-->0;) {
		string what, order;
		int time;
		cin >> what >> order >> time;
		cout << "Query: " << what << ' ' << order << ' ' << time << '\n';

		if (order == "asc") { /*{{{*/
			if (what == "id") {
				auto it = id_map.begin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else if (what == "name") {
				auto it = name_map.begin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else if (what == "year") {
				auto it = year_map.begin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else { // what == "salary"
				auto it = salary_map.begin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			}
/*}}}*/
		} else { // order == "desc"{{{

			if (what == "id") {
				auto it = id_map.rbegin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else if (what == "name") {
				auto it = name_map.rbegin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else if (what == "year") {
				auto it = year_map.rbegin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			} else { // what == "salary"
				auto it = salary_map.rbegin();
				while (time) for (auto jt : (it++)->second) {
					cout << db[ jt ] << '\n';
					if (--time == 0) break;
				}
			}

		} /*}}}*/
	}

	return 0;
}

