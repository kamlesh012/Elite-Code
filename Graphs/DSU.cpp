//Disjoint Set Union COde.
//Disjoint Set is a Graph Based Data Structure
#include <iostream>
using namespace std;
//Time Complexity if Alpha(n) Amortized Time Complexity.
//Almost COnstant. Even for large n average value of ALpha is 4
int parent[100000];
int Rank[100000];
int size[100000];

void make_set(int v) {
	for (int i = 0; i <= v; i++) {
		parent[i] = i;
		Rank[i] = 0;
		size[i] = 1;
	}
}

void make(int v) {
	parent[v] = v;
	Rank[v] = 0;
	size[v] = 1;
}

int findParent(int v) {
	if (v == parent[v])return v;
	// return findParent(parent[v]);

	//Path Compression
	return parent[v] = findParent(parent[v]);
}

void unionBySize(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		if (a < b)swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

void unionByRank(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (Rank[a] == Rank[b]) {
		Rank[a]++;
		parent[b] = a;
	}
	else if (Rank[a] > Rank[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

//Find Connected Components
int findConnectedComponents(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (findParent(i) == i)cnt++;
	}
	return cnt;
}
//CHeck if two nodes belong to same component or not
bool sameComponent(int a, int b) {
	// return parent[a]==parent[b];	//wrong but why?
	return findParent(a) == findParent(b);
}

int main() {
	int n, t; cin >> n >> t;
	make_set(n);
	//or
	// for(int i=1;i<=n;i++)make(i);

	while (t--) {
		int u, v; cin >> u, v;
		unionByRank(u, v);
		// unionBySize(u, v);
	}


	return 0;
}
