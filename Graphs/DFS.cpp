dfs(curr_node,visited[]){
    visited[curr_node]=1;
    for(i->0 to adj[curr_node].size()){
        if(!visited[adj[curr_node][i]]){
            dfs(adj[curr_node][i],visited);
        }
    }
}