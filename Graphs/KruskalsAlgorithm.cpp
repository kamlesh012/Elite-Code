//Kruskal's Algorithm->Generates MST for undirected weighted graph.

/*Approach->

1->Store all nodes along with their weights in edge list
	representation using structure or pair<int,pair<int,int>>

2->Sort the nodes in increasing order of the edge weights
	(so that we can greedily start with the node having least weight
	&& so on to form out Minimum Spanning Tree)

3->Now iterate greedily from lowest weight to highest && :-
	if source & destination nodes belong to same component
	(have same parent) then add to MST.
	else don't add since they are already in same component,adding
	them will create a cycle.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Node that stores source vertex,destination vertex & weight
struct node {
	int u, v, wt;
	//constructor for auto initilisation.
	node(int u, int v, int wt) {
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};

//Parent & Ranks array for Disjoint Set
int parent[10000];
int Rank[10000];

//Makes a Disjoint set having n nodes where
//each node is parent of itself & rank of each node is zero
void make_set(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		Rank[i] = 0;
	}
}

//Recursively Finds Parent of a given node.
int findParent(int n) {
	if (parent[n] == n)return n;
	//Path Compressed
	return parent[n] = findParent(parent[n]);

	//without path compression might take O(logn) in worst case.
	// return findParent(parent[n]);
}

void Union(int a, int b) {

	a = findParent(a);
	b = findParent(b);
	///Striver's method for Union by Rank

	if (Rank[a] == Rank[b]) {	//if rank is equal choose one
		Rank[a]++;				//as parent & increase its rank
		parent[b] = a;

	}			//else always choose higher ranked component as parent
	else if (Rank[a] > Rank[b]) {
		parent[b] = a;
	}
	else if (Rank[b] > Rank[a]) {
		parent[a] = b;
	}

}

bool comp(node a, node b) {
	//Custom Comparator to sort node by weights
	return a.wt <= b.wt;
}

void Kruskal(vector<node> edgelist, int n) {

	vector<pair<int, int>> mst;
	int cost = 0;

	make_set(n);	//initiliases all n nodes .
	sort(edgelist.begin(), edgelist.end(), comp);
	//sorts in increasing order of the weights

	for (int i = 0; i < n; i++) {

		int source = edgelist[i].u;
		int destination = edgelist[i].v;
		int weight = edgelist[i].wt;

		if (findParent(source) != findParent(destination)) {
			Union(source, destination);
			mst.push_back({source, destination});
			cost += weight;
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << mst[i].first << "-> " << mst[i].second << endl;
	cout << "Minimum Cost is:->" << cost << endl;
}

int main() {

	int nodes, edges;
	cin >> nodes >> edges;

	vector<node> edgelist;

	for (int i = 0; i < edges; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		node curr = node(u, v, wt);
		edgelist.push_back(curr);
	}

	Kruskal(edgelist, nodes);

	return 0;
}



