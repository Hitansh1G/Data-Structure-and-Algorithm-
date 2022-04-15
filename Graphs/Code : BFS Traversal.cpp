#include <bits/stdc++.h>
using namespace std;
void bfs(int **graph , int n , int start , bool *visited){
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<n;i++){
              if(i==node)
    	  {
    	   continue;
    	  }
            if(graph[node][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
  	}	
	// cout<<endl;
}
 

void bfs(int **graph,int n){
	bool *visited=new bool[n];
    for(int i=0;i<n;i++){
    	visited[i]=false;
    } 
    for(int i=0;i<n;i++){
    	if(!visited[i]){
        	bfs(graph,n,i,visited);
        }
    }
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int **graph = new int*[v];
    for(int i=0 ; i<v ; i++){
        graph[i] = new int[v];
        for(int j=0 ; j<v; j++){
            graph[i][j]==0;
        }
    }
    for(int i=0 ; i<e ; i++){
        int a,b;
        cin >> a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    bool *visited = new bool[v];
    for(int i=0 ; i<v ; i++){
        visited[i]= false;
    }
    // bfs(graph,v,0,visited);
    bfs(graph,v);
}