#include<bits/stdc++.h>
int max( int a, int b ){
    return a>b?a:b;
}
int maxMoneyLooted(int arr[], int n, int*  dp){
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2 ;i< n ;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[n-1];
}
int maxMoneyLooted(int arr[], int n){
	int  dp[n];
   	return maxMoneyLooted(arr,n, dp);
}