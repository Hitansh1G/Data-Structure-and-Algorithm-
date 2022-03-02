// #include<bits/stdc++.h>
// int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
//     // Write your code here
//     unordered_map<int,int> m;
//     vector <int> pre;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0)
//             arr[i]=-1;
//     }
//     pre.push_back(arr[0]);
    
//     for (int i=1;i<n;i++)
//         pre.push_back(pre[i-1]+arr[i]);
//     /*
//     for (int i=0;i<n;i++)
//         cout<<pre[i]<<" ";
//     cout<<"\n"<<endl;
//     */
//     int c=0;
//     for(int i=0;i<n;i++){
        
//         if(m.count(pre[i])){
//             c=max(c,i-m[pre[i]]);
//         }
//         else
//             m[pre[i]]=i;
//         if(pre[i]==0)
//             c=max(c,i+1);   
//     }
//     return c;

// }

// approach is like  95 -97 -387 -435 -5 -70 897 127 23 284 is present
// so in key we put sum and in value we put index
// now check from the starting _____sum______samesum___________  
//                                   ^         ^
//                                   |         |   
// then we have to find the length so we do samesum-sum , in this way we will find the length as length = samesum-sum
#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int , int>index;          // key = sum , value=index
                      
    int sum=0; 
    int length=0;
    for(int i=0; i<n; i++)
    {         
       sum+=arr[i];
        if(sum==0)
     {  
            length = i+1;          // this is the case when there is only one sum =0 and 
     } 
        
        if(index.count(sum)==1)
        {
            length = max(length, i-index[sum]); // always remember whenever in map we put key we get value;
        }                                     // very important point;
        
      else
      {
          index[sum]=i;       // now adding index  in map
      }        
    }
    
    
    return length;
    
}