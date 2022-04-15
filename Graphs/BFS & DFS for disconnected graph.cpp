void DFS(int **edges , int n){
    bool *visited = new bool[n];
    for(int i=0 ; i<n ; i++){
        visited[i]=false;
    }
    for(int i=0 ; i<n ; i++){
        if(!visited[i])
            printDFS(edges,n,i,visited);
    }
    delete []visited;

}
void BFS(){
    bool *visited = new bool[n];
    for(int i=0 ; i<n ; i++){
        visited[i]=false;
    }
    for(int i=0 ; i<n ; i++){
        if(!visited[i])
            printBFS(edges,n,i,visited);
    }
    delete []visited;

}