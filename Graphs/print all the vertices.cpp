#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
// typedef long long ll;
using namespace std;
// void print(int **edges , int n , int startingVertex, bool* visited){
//     cout << startingVertex << endl;
//     visited[startingVertex]= true;
//     for(int i=0 ; i< n ; i++){
//         if(i==startingVertex) continue;
//         if(edges[startingVertex][i]==1){
//             if(visited[i]==true){
//                 continue;
//             }
//             print(edges,n,i,visited);
//         }
//     }
// }
// int main(){
//     Fast
//     int n,e;
//     cin >> n >> e;
//     int ** edges = new int*[n];
//     for(int i=0 ; i<n ; i++){
//         edges[i]= new int[n];
//         for(int j=0 ; j<n ; j++){
//             edges[i][j]=0;
//         }
//     }
//     for(int i=0 ; i<n ; i++){
//         int f,s;
//         cin >> f >> s;
//         edges[f][s]=1;
//         edges[s][f]=1;
//     }
//     bool* visited = new bool[n];
//     for(int i=0 ; i<n ; i++){
//         visited[i]=false;
//     }
//     print(edges,n,0,visited);
//     return 0;
// }



vector<vector< int > > adj;
// dding edge between 2 vertices in the graph 
void addEdge(int x, int y){
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void dfs(int start, vector<bool>& visited){
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++) {

		// If some node is adjacent to the current node
		// and it has not already been visited
		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i, visited);
		}
	}
}

int main()
{
	// number of vertices
	int v = 5;

	// number of edges
	int e = 4;

	// adjacency matrix
	adj = vector<vector<int> >(v, vector<int>(v, 0));

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(0, 4);

	// Visited vector to so that a vertex is not visited more than once
	// Initializing the vector to false as no vertex is visited at the beginning

	vector<bool> visited(v, false);
	dfs(0, visited);
}

