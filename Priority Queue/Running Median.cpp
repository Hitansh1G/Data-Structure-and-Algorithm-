#include<queue>
using namespace std;
void findMedian(int *arr, int n)
{
    // Write your code here
//     priority_queue <int> max;
//     priority_queue <int, vector<int>, greater<int>> min;
    
//     for(int i=0 ;i<n ;i++){
//         if(i==0){
//             max.push(arr[i]); 
//         }
//         else{
//             if(arr[i] < max.top())
//                 max.push(arr[i]);
//             else 
//                 min.push(arr[i]);
//          }
//         if(int(max.size()-min.size() )> 1){
//         	int x=max.top();
//            	max.pop();
//            	min.push(x);
//         }
//         else if(int(min.size()-max.size()) > 1){
//             int x=min.top();
//            	min.pop();
//            	max.push(x);
//         }
//         int c=max.size()+min.size(); 
//         if(c%2==0)
//             cout<<(max.top()+min.top())/2<<endl;
//         else{
//             if(max.size()>min.size())
//                 cout<<max.top()<<" ";
//             else
//                 cout<<min.top()<<" ";
//         }
//     }
    
    
    if(n<=0) return; 
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    int median=arr[0];
    for(int i=0; i<n; i++){
        if(minHeap.size()==maxHeap.size()){
            if(arr[i]<median){
                maxHeap.push(arr[i]);
                median = maxHeap.top();
            }
            else{
                minHeap.push(arr[i]);
                median = minHeap.top();
            }
        }
        else if(minHeap.size()>maxHeap.size()){
            if(arr[i]<median){
                maxHeap.push(arr[i]);
                median = (maxHeap.top() + minHeap.top())/2;
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
                median = (maxHeap.top() + minHeap.top())/2;
            }
        }
        else{
            if(arr[i]<median){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
                median = (maxHeap.top() + minHeap.top())/2;
            }
            else{
                minHeap.push(arr[i]);
                median = (maxHeap.top() + minHeap.top())/2;
            }
        }
        cout << median<<" ";
    }
}