/* Unique Paths II

We are given an “ N*M ” Maze. The maze contains some obstacles. A cell is ‘ blockage ’ in the maze if its value is -1. 0  represents non-blockage. There is no path possible through a blocked cell.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. At every cell, we can move either down or towards the right.*/



int f(int i,int j,vector< vector< int>>&a){
if (i==0 && j==0) return 1;

	if(i<0 || j<0 || a[i][j]==-1)return 0;

	int up= f(i-1,j,a);
	int left=f(i,j-1,a);

	return up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   return f(n-1,m-1,mat);
}





Time Complexity:   O(2^(M*N))
Space Complexity:  O(M-1)+O(N-1)







int mod =(int)(1e9+7);
int f(int i,int j,vector< vector< int>>&a,vector<vector<int>> &dp){
if (i==0 && j==0) return 1;

	if(i<0 || j<0 || a[i][j]==-1)return 0;
     if(dp[i][j] != -1) return dp[i][j];
	int up= f(i-1,j,a,dp);
	int left=f(i,j-1,a,dp);

	return dp[i][j]=(up+left)%mod ;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	vector<vector<int>>dp(n,vector<int>(m,-1));
   return f(n-1,m-1,mat,dp);
}





Time Complexity:   O(M*N)
Space Complexity:  O(M-1)+O(N-1) + O(M*N)







int mod =(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	int dp[n][m];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
			if(mat[i][j]==-1)dp[i][j]=0;
			else if (i == 0 && j == 0)dp[i][j] = 1;
            else {
                int up = 0, left = 0;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = (up + left)%mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}




Time Complexity:   O(M*N)
Space Complexity:  O(M*N)







int mod =(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	vector<int>prev(m,0);
	for (int i = 0; i < n; i++) {
		vector<int>curr(m,0);
        for (int j = 0; j < m; j++) {
			if(mat[i][j]==-1)curr[j]=0;
			else if (i == 0 && j == 0)curr[j] = 1;
            else {
                int up = 0, left = 0;

                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left =curr[j - 1];
                curr[j] = (up + left)%mod;
            }
        }
		prev=curr;
    }
    return prev[m- 1];
}






Time Complexity:   O(M*N)
Space Complexity:  O(N)
