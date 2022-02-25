#include<bits/stdc++.h>
int highestFrequency(int *arr, int n){	 
 	unordered_map<int,int> frequency;
    int maxFrequency = 0;
	int maxElement = 0;
    for (int i = 0; i < n; ++i){
		frequency[arr[i]]++;
		maxFrequency = max( maxFrequency, frequency[arr[i]]);
	} 
    for (int i = 0; i < n; ++i){
		if(maxFrequency == frequency[arr[i]]){
			maxElement = arr[i];
			break;
		}
	}
    return maxElement;
}