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
typedef long long ll;
using namespace std;
void print(int **edges , int n , int sv, bool* visited){
    cout << sv << endl;
    visited[sv]= true;
    for(int i=0 ; i< n ; i++){
        if(i==sv) continue;
        if(edges[sv][i]==1){
            if(visited[i]==true){
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}
int main(){
    Fast
    int n,e;
    cin >> n >> e;
    int ** edges = new int*[n];
    for(int i=0 ; i<n ; i++){
        edges[i]= new int[n];
        for(int j=0 ; j<n ; j++){
            edges[i][j]=0;
        }
    }
    for(int i=0 ; i<n ; i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited = new bool[n];
    for(int i=0 ; i<n ; i++){
        visited[i]=false;
    }
    print(edges,n,0,visited);
    return 0;
}