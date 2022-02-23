#include<queue>
#include<iostream>

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> p;
    for(int i=0;i<n ;i++)
         p.push(i);
    priority_queue <int > pq;
    for(int i=0 ; i<n ;i++){
        pq.push(arr[i]);
    }
    int time=0;
    while( p.front()!=k || pq.top()!= arr[p.front()] ) {   
        if(pq.top()>arr[p.front()]){
        	int x=p.front();
            p.pop();
           	p.push(x);
        }
        else if(pq.top()==arr[p.front()]){
            pq.pop();
          	p.pop();
           	time++;			
        }
    }
    return time+1;  
}