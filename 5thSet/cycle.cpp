#include <iostream>
#include <vector>

using namespace std;

class Graph {
	public:
		Graph (int v);
		~Graph();
		void addEdge (int u, int v) noexcept;
		bool cycle (vector<int>& path) const noexcept;
};

int main() {
	int V, E;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; ++i) {
		int u, v; cin >> u >> v; g.addEdge(u, v);
	}
	vector<int> path;
	bool c = g.cycle(path);
	if (c) {
		cout << "CYCLE: ";
			for (int i = 0; i < path.size(); ++i)
				cout << path[i] << (i == path.size()-1 ? "\n" : " ");
	} else {
		cout << "NO CYCLE" << endl;
	}
	return 0;
}
