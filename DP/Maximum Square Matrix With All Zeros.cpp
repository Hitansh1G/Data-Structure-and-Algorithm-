int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
	//Write your code here
    int **storage;
    storage = new int*[row+1];
    for(int i=0; i<=row; i++)
    {
        storage[i] = new int[col+1];
        for(int j=0; j<=col; j++)
            storage[i][j] = 0;
    }
    for(int i=row-1; i>=0; i--)
        for(int j=col-1; j>=0; j--)
        {
            int maximum = storage[i][j] = max(storage[i+1][j], storage[i][j+1]);

            if(min(row-i, col-j)<=maximum)
                continue;

            bool foundOne = false;
            for(int p=0; p<=maximum; p++)
                for(int q=0; q<=maximum; q++)
                    if(arr[i+p][j+q]==1){
                        foundOne = true;
                        p = q = maximum+1;
                    }
            if(foundOne==false)
                storage[i][j] += 1;
        }
    int ans = storage[0][0];
    for(int i=0; i<=row; i++)
        delete [] storage[i];
    delete [] storage;
    return ans;
}