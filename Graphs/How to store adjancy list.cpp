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
int32_t main(){
    Fast
    int n,m;
    cin >> n >> m;
    vector<int>ajd[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v;
        cin >> u >> v ;

        ajd[u].push_back(v);
        ajd[v].push_back(u);
    }
    return 0;
}