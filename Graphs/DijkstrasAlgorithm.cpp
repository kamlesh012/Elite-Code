//Dijkstra'a Algorithm->Single Source Shortest Path in Weighted Graph
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
void Dijkstra(vector<pair<int, int>> adjlist[], int nodes) {

	vector<int> dist(nodes + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	int start = 0;
	dist[start] = 0;
	q.push({dist[start], start});

	while (!q.empty()) {
		int node = q.top().second;
		q.pop();

		for (auto i : adjlist[node]) {

			if (dist[i.first] > dist[node] + i.second) {
				dist[i.first] = dist[node] + i.second;
				q.push({dist[i.first], i.first});
			}
		}
	}
	for (int i = 0; i < nodes; i++)
		cout << dist[i] << " "; cout << endl;
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	vector<pair<int, int>> adjlist[nodes + 1];

	for (int i = 0; i < edges; i++) {
		int u, v, w; cin >> u >> v >> w;
		adjlist[u].push_back({v, w});
		adjlist[v].push_back({u, w});
	}
	Dijkstra(adjlist, nodes);

	return 0;
}