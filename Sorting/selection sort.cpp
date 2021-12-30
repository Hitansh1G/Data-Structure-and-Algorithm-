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
using namespace std;
void selectionSort(int input[], int n){
    for(int i=0 ; i<n-1 ; i++){
        int min=input[i],minIndex=i;
        for(int j=i+1 ; j< n ; j++){
            if (input[j]<min){
                min = input[j];
                minIndex=j;
            }
        }
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}
int main(){
    Fast
    int input[]={3,1,6,9,0,4};
    selectionSort(input,6);
    for(int i=0 ; i<6 ; i++){
        cout<<input[i]<<" ";
    }
    return 0;
}