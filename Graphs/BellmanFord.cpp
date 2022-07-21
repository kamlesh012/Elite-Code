//Bellman Ford->Single Source Shortest Path in Weighted Graph
//with Negative Edge Weights
//ALSO CHECKS FOR NEGATIVE EDGE CYCLES
//Takes edges with weights & source as input.
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

struct node {
	int u, v, w;
	node(int first, int second, int wt) {
		u = first;
		v = second;
		w = wt;
	}
};

void Bellman(vector<node> adjlist, int nodes, int edges, int source) {

	vector<int> dist(nodes + 1, INT_MAX);
	dist[source] = 0;

	for (int i = 1; i < nodes - 1; i++) {
		//iterate nodes-1 times
		for (int j = 0; j < edges; j++) {
			int u = adjlist[j].u;
			int v = adjlist[j].v;
			int w = adjlist[j].w;
			if (dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 1; i < edges; i++) {
		int u = adjlist[i].u;
		int v = adjlist[i].v;
		int w = adjlist[i].w;

		if (dist[v] > dist[u] + w) {
			cout << "NEGATIVE EDGE CYCLE";
			return;
		}
	}

	for (int i = 0; i < nodes; i++) {
		cout << i << " " << dist[i] << endl;
	}


}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	vector<node> adjlist;

	for (int i = 0; i < edges; i++) {
		int u, v, w; cin >> u >> v >> w;
		adjlist.push_back(node(u, v, w));
	}
	int source; cin >> source;

	Bellman(adjlist, nodes, edges, source);

	return 0;
}