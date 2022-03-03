#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
 
int BS(int arr[], int X, int low, int N){
    int high = N - 1;
    int ans = N;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= X) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int getPairsWithDifferenceK(int *arr, int N, int k) {
	// Write your code here
	// unordered_map<int,int> m;
	// int count=0;
	// for(int i=0 ; i< n ;i++){
	// m[input[i]]++;
	// }
	// if(k!=0){
	// for(int i=0 ; i<n ;i++){
	// if(m.count(input[i]-k)>0){
	// // m[input[i]]--; 
	// int j=0;
	// while(j<m[input[i]-k]){
	// if((input[i]-k)<input[i])
	// count++;
	// else
	// count++;
	// j++;  
	// }
	// }
	// }
	// }
	// else if(k==0){
	// for(int i=0;i<n;i++){
	// 		if(m.count(input[i])>0){
	// 			for(int j=0;j<m[input[i]]-1;j++){
	// count++;
	// }
	// m[input[i]]--;
	// }
	// }
	// }
	// return count;
    int count = 0;
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        int X = BS(arr, arr[i] + k, i + 1, N);
        if (X != N) {
            int Y = BS(arr, arr[i] + k + 1, i + 1, N);
            count += Y - X;
        }
    }
    return count;
}