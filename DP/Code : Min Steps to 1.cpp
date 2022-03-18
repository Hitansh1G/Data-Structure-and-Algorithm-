#include<bits/stdc++.h>
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n==1) return 0;
    int a=INT_MAX,b=a,c=b;
    a=countMinStepsToOne(n-1);
    if(n%2==0){
        b=countMinStepsToOne(n/2);
    }
    if(n%3==0){
        c=countMinStepsToOne(n/3);
    }
    return  1+min(a,min(b,c));
}