//Basic Graph Algorithms
//bfs
//dfs
//cycle detection using bfs/dfs.
//bipartite using bfs/dfs
//shortest path in undirected(unit weights)
//shortest path in Weighted DAG

#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findPathBFS(vector<int> adjlist[], int nodes, vector<int> visited, int dist[], int start) {

	visited[start] = 1;
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : adjlist[x]) {
			visited[i]++;
			dist[i] = min(dist[x] + 1, dist[i]);
		}
	}
	for (int i = 1; i <= nodes; i++)cout << dist[i] << ' '; cout << endl;
}

void ShortestPathUnitWeights(vector<int> adjlist[], int nodes)
{
	//Find Shortest Path in a Undirected Graph
	//with unit wieghts.
	//if we have to find shortest path in a DAG with
	//weights then first we apply topo Sort & then apply
	//the same procedure on vertices in topo sort order
	//so that we won't have to update shortest path for

//a node each time its child finds another shortest path.
	int dist[nodes + 1];

	for (int &i : dist) {
		i = INT_MAX;
	}
	vector<int> visited(nodes + 1, 0);
	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			findPathBFS(adjlist, nodes, visited, dist, i);
		}
	}
}


//Use two visited arrays.one as usual
//another to check whether the next vertex has been already
//directly visited in this same direction before.
//A Cycle will occur only when a vertex has been visited by any node
//and that same vertex has been visited by some other node in this
//same direction before.
//if all neighbours of a vertex are visited then
//we need to move in another direction & set direct_visited[i] to zero
//to mark that this vertex has been visited but cycle no found in this direction
//so we are again marking it zero.in case some other vertex reaches
//this veretx from another direction then they will set direct_Vertex[i]

bool isCycleDirected(vector<int>&visited, vector<int>& direct_visited, vector<int> adjlist[], int nodes, int start) {

	visited[start] = 1;		//Mark this starting node as visited
	//for this connected component
	direct_visited[start] = 1;

	for (auto i : adjlist[start]) {
		if (!visited[i]) {
			if (isCycleDirected(visited, direct_visited, adjlist, nodes, i))
				return true;
		}
		else if (visited[i] && !direct_visited[i])continue;
		else if (direct_visited[i] && visited[i])return true;
	}
	direct_visited[start] = 0;
	return false;

}

bool detectCycleDFS_Directed(vector<int> adjlist[], int nodes) {

	vector<int> visited(nodes + 1, 0);
	vector<int> direct_visited(nodes + 1, 0);
	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			if (isCycleDirected(visited, direct_visited, adjlist, nodes, i))return true;
		}
	}
	return false;
}



bool isBipartiteDFS(vector<int> adjlist[], vector<int>&color, int start) {

	if (color[start] == -1)color[start] = 0;

	for (auto i : adjlist[start]) {
		if (color[i] == -1) {
			color[i] = 1 - color[start];
			if (!isBipartiteDFS(adjlist, color, i))return false;
		}
		else if (color[i] == color[start])return false;
	}
	return true;
}

bool checkBipartiteDFS(vector<int> adjlist[], int nodes) {

	vector<int> color(nodes + 1, -1);

	for (int i = 1; i <= nodes; i++) {

		if (color[i] == -1) {
			// color[i] = 0;	//either this or
			//first line of above function
			if (!isBipartiteDFS(adjlist, color, i))return false;
		}

	}

	return true;

}

bool isBipartiteBFS(vector<int> adjlist[], int nodes, vector<int>& color, int start)
{
	queue<int> q;
	q.push(start);

	color[start] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto i : adjlist[node]) {
			if (color[i] == -1) {
				color[i] = 1 - color[node];
				q.push(i);
			}
			else if (color[i] == color[node])return false;
		}

	}
	return true;
}

bool checkBipartiteBFS(vector<int> adjlist[], int nodes) {

	vector<int> color(nodes + 1, -1);

	for (int i = 1; i <= nodes; i++) {

		if (color[i] == -1) {
			if (!isBipartiteBFS(adjlist, nodes, color, i))return false;
		}

	}

	return true;

}

bool isCycleDFS(vector<int>&visited, vector<int> adjlist[], int nodes, int start, int parent) {

	visited[start] = 1;		//Mark this starting node as visited
	//for this connected component

	for (auto i : adjlist[start]) {
		if (!visited[i]) {
			isCycleDFS(visited, adjlist, nodes, i, start);
		}
		else if (i != parent)return true;
	}
	return false;

}

bool detectCycleDFS(vector<int> adjlist[], int nodes) {
	vector<int> visited(nodes + 1, 0);

	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			if (isCycleDFS(visited, adjlist, nodes, i, -1))return true;
		}
	}
	return false;
}


bool isCycleBFS(vector<int>&visited, vector<int> adjlist[], int nodes, int start) {

	queue<pair<int, int>> q;
	q.push({start, -1});

	visited[start] = 1;		//Mark this starting node as visited
	//for this connected component

	while (!q.empty()) {

		int curr_node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for (auto i : adjlist[curr_node]) {

			if (!visited[i]) {		//if neighbours not visited
				visited[i]++;			//mark neighbours visited
				q.push({i, curr_node});
			}
			else if (parent != i)	//else if visited but not parent
				return true;
		}
	}

	return false;

}

bool detectCycleBFS(vector<int> adjlist[], int nodes) {

	vector<int> visited(nodes + 1, 0);

	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			if (isCycleBFS(visited, adjlist, nodes, i))return true;
		}
	}
	return false;
}

void dfs(vector<int> adjl[], vector<int>&visited, vector<int>& ans, int start) {

	ans.push_back(start);

	visited[start] = 1;	//mark current root

	for (auto i : adjl[start]) {
		//only apply dfs if current node is visited.
		if (!visited[i])dfs(adjl, visited, ans, i);
	}

}

void DFS_Graph(vector<int>adjl[], int nodes) {

	vector<int> visited(nodes + 1, 0);
	vector<int> ans;

	for (int i = 1; i <= nodes; i++) {

		if (!visited[i]) {		//checks if current node is visited as root
			dfs(adjl, visited, ans, i);
			for (auto i : ans)cout << i << " "; cout << endl;
			ans.clear();
		}

	}

}

void BFS_Graph(vector<int> adjl[], int nodes) {

	vector<int> visited(nodes + 1, 0);

	for (int i = 1; i <= nodes; i++) {

		if (visited[i])continue;

		vector<int> bfs;
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			if (!visited[node]) {

				bfs.push_back(node);
				visited[node]++;

				for (auto i : adjl[node]) {
					q.push(i);
				}
			}
		}

		for (auto i : bfs)cout << i << " "; cout << endl;

	}
}

int main() {

	//Representation in C++;

	int nodes, edges; cin >> nodes >> edges;

	//Adjacency List
	vector<int> adjlist[nodes + 1];
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	// BFS_Graph(adjlist, nodes);
	// DFS_Graph(adjlist, nodes);
	// cout << detectCycleBFS(adjlist, nodes) << endl;
	// cout << detectCycleDFS(adjlist, nodes) << endl;

	// cout << checkBipartiteBFS(adjlist, nodes) << endl;
	// cout << checkBipartiteDFS(adjlist, nodes) << endl;

	cout << detectCycleDFS_Directed(adjlist, nodes) << endl;
	//Adjacency Matrix
	// int adjmatrix[n+1][n+1]={0};
	// for(int i=0;i<nodes;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	adjmatrix[u][v]=1;
	// 	adjmatrix[v][u]=1;
	// }

	return 0;
}

void BFS_Matrix(int adjm[][5], int nodes) {

	vector<int> visited(nodes + 1, 0);
	for (int start = 1; start <= nodes; start++) {

		if (!visited[start]) {

			vector<int> ans;
			queue<int>q;
			q.push(start);
			visited[start] = 1;

			while (q.empty()) {

				int node = q.front();
				q.pop();

				ans.push_back(node);

				for (int i = 1; i <= nodes; i++) {
					int child = adjm[node][i];
					if (child && !visited[i]) {
						visited[i]++;
						q.push(i);
					}
				}
			}
			for (auto i : ans)cout << i << " "; cout << endl;
		}
	}
}

void DFS(int adjm[][5], int nodes, vector<int>&visited, int start, vector<int>&ans) {

	visited[start] = 1;
	ans.push_back(start);

	for (int i = 1; i <= nodes; i++) {

		if (adjm[start][i] && !visited[i]) {
			DFS(adjm, nodes, visited, i, ans);
		}
	}
}

void DFS_Matrix(int adjm[][5], int nodes) {

	vector<int> visited(nodes + 1, 0);

	for (int i = 1; i <= nodes; i++) {

		if (!visited[i]) {

			vector<int> ans;
			DFS(adjm, nodes, visited, i, ans);
			for (auto i : ans)cout << i << " "; cout << endl;

		}
	}

}

