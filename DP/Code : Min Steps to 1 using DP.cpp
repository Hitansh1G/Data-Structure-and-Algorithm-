#include<bits/stdc++.h>
int countStepsToOne(int n)
{
	//Write your code here
    int a[n+1]; 
    a[1]=0; a[2]=a[3]=1;
    int b,c;
    for(int i=4 ;i<n+1;i++){   
        b=c=n;
        if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
        a[i]=1+ min(a[i-1] ,min(b,c));
    }
    return a[n];
}