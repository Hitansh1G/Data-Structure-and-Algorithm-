int minCostPath(int **input, int m, int n)
{
	//Write your code here
    for(int j=1; j<n; j++)
        input[0][j] += input[0][j-1];
    for(int i=1; i<m; i++)
        input[i][0] += input[i-1][0];
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            input[i][j] += min(min(input[i-1][j],input[i][j-1]),input[i-1][j-1]);

    return input[m-1][n-1];
}