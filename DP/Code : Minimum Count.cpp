int minCount(int n)
{
	//Write your code here
    if(n<0) n *= -1; 
    int s = sqrt(n);
    if(s*s==n) return 1; 
    int *ans = new int[n+1];
    for (int i=0;i<=n;i++){
        s = sqrt(i);
        if(s*s==i){
            ans[i] = 1;
            continue;
        }
        ans[i] = 1 + ans[i-1];
        for (int j=2;j<s;j++){
            int alternate = 1 +    ans[i-(j*j)];
            if( alternate<ans[i])
                ans[i] = alternate;
        }
    }
    int result = ans[n];
    delete [] ans;
    return result;
}