#include <bits/stdc++.h>
using namespace std;

// void dfs(int**graph,int node,bool* visited){
//     visited[node]=true;
    
//     for(int i=0;i<adj[node].size();i++){
//         if(!visited[adj[node][i]])
//             dfs(adj,adj[node][i],visited);
//     }
// }
void printDFS(int** graph ,int v,int s,bool* visited ){ 
    visited[s]= true;
    for(int i =0 ;i< v ;i++){
        if(i == s) {
            continue;
        }
        if(!visited[i]&& graph[s][i]==1)
    	printDFS( graph ,v, i ,visited);
    }
}
int solve(int n,int m,vector<int>u,vector<int>v){
	int** graph = new int *[n];
    for(int i=0 ;i < n ;i++){
        graph[i]=new int[n];
        for( int j=0 ;j<n ;j++)
            graph[i][j]=0; 
    }
    for(int i=0 ;i< m ;i++){
        graph[u[i]][v[i]]=1;
        graph[v[i]][u[i]]=1;
    }
    bool *visited=new bool[n];
    for(int i=0 ;i<n;i++)
        visited[i]= false;
    
	int total=0;
    
    for(int i=0; i< n ;i++){
   		 if(visited[i] == false){
             total++;
             printDFS(graph,n, i,visited );
         }   
	}
    delete []  visited;
    for(int i = 0 ;i <n ;i++)
        delete [] graph[i];

    delete[] graph;
    
    return total;
}
int main(){
	int n,m;
    
    
	vector<int>u,v;
	cin>>n>>m;
    
    if(m == 0) {
        // edge case
        cout << n << endl;
        return 0;
    }
    
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		u.push_back(x);
        v.push_back(y);
	}
	
	cout<<solve(n,m,u,v)<<endl;
    return 0;
}