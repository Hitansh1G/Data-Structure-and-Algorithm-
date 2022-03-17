int fibo_helper(int n, int *ans){
    if(n<=1){
        return 1;
    }
    if(arr[n] != -1){
        return ans[n];
    }
    int a = fibo_helper(n-1,ans);
    int b = fibo_helper(n-2,ans);
    ans[n] = a+b;
    return ans[n];
}
int fibo_2(int n){
    int *ans= new int[n+1];

    for(int i=0 ; i<n ; i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}