int longestIncreasingSubsequence(int* arr, int n) {
    int dp[n];
	dp[0] = 1;
	for (int i = 1; i < n ; i++){
		int ans = 0;
		for (int  j = i - 1 ; j >= 0 ; j--){
			if (arr[j] < arr[i]){
				ans = max(dp[j], ans);
			}
		}
		dp[i] = ans + 1;
	}
	int res = 0;
	for (int i = 0 ; i < n ; i++)
		res = max(dp[i], res);
	return res;
}