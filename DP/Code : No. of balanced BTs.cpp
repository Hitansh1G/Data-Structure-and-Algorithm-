int balancedBTs(int h) {
    // Write your code here
    #define M 1000000007
    if(h<=1) return 1;
    long *ans = new long[h+1];
    ans[0] = ans[1] = 1;
    for (int i=2 ; i<=h ; i++){
        long a = (ans[i-1]*ans[i-1]) % M;
        long b = (2*ans[i-1]*ans[i-2]) % M;
        ans[i] = (a + b) % M;
    }

    int result = (int)ans[h];
    delete [] ans;
    return result;
}