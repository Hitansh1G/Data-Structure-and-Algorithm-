#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int staircase(int n){
    long a[n+1];
    a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    
    for(int i=4 ; i<=n ; i++){
        a[i]=(a[i-1] + a[i-2] + a[i-3])%mod;
    }
    return a[n];
}

int main(){
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<staircase(n)<<endl;
    }
    return 0;
}