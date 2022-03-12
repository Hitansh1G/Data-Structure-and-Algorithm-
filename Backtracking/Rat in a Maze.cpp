// #include<iostream>
// #include<string>
// #include<algorithm>
// #include<vector>
// #include<map>
// #include<set>
// #include<list>
// #include<queue>
// #include<stack>
// #include<cstring>
// #include<cmath>
// #include<cstdlib>
// #include<unordered_map>
// #include<unordered_set>
// #define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
// typedef long long ll;
// using namespace std;
// void printSolution(int ** solution , int n){
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<n ; j++){
//             cout << solution[i][j]<<" ";
//         }
//     }
//     cout<<endl;
// }
// void mazeHelp(int maze[][20],int n, int** solution,int x ,int y){

//     if(x==n-1 && y==n-1){
//         solution[x][y]=1;
//         printSolution(solution,n);
//         return;
//     }
//     if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || solution[x][y]==1){
//         return;
//     }
//     solution[x][y]=1;
//     mazeHelp(maze,n,solution,x-1,y);//up
//     mazeHelp(maze,n,solution,x+1,y);//down
//     mazeHelp(maze,n,solution,x,y-1);//left
//     mazeHelp(maze,n,solution,x,y+1);//right
//     solution[x][y]=0;
// }
// void ratinamaze(int maze[][20],int n){
//     int **solution=new int*[n];
//     for(int i=0 ; i<n ; i++){
//         solution[i] = new int*[n];
//     }
//     mazeHelp(maze,n,solution,0,0);
// }

// int main(){
//     Fast
//     int n;
//     cin >> n;
//     int maze[n][n];
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<n ; j++){
//             cin >> maze[i][j];
//         }
//     }
//     ratinamaze(maze,n);
//     return 0;
// }
/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<bool>> &visited){
    for(int i=0;i<visited.size();i++){
        for(int j=0;j<visited[i].size();j++){
            cout<<visited[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
void helper(int **maze,int n,vector<vector<bool>> &visited,int i,int j){
    if(i>=n||i<0||j>=n||j<0||maze[i][j]==0||visited[i][j]==true)
        return;
    visited[i][j]=true;
    if(i==n-1&&j==n-1){
        print(visited);
        visited[i][j]=false;
        return;
    }
    helper(maze,n,visited,i-1,j);
    helper(maze,n,visited,i+1,j);
    helper(maze,n,visited,i,j-1);
    helper(maze,n,visited,i,j+1);
    visited[i][j]=false;
}
int main() {
 
    int n;
    cin>>n;
    int **maze=new int*[n];
    for(int i=0;i<n;i++){
        maze[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    }
   	vector<vector<bool>> visited(n,vector<bool>(n,false)); 
    helper(maze,n,visited,0,0);
    for(int i=0;i<n;i++)
        delete []maze[i];
    delete []maze;
	return 0;
}
 