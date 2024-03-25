
/*Minimum Path Sum In a Grid 

We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.
At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.*/



#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &grid){
    if(i==0&&j==0)return grid[i][j];
    if(i<0||j<0)return 1e9 ;
    int up = grid[i][j]+f(i-1,j,grid);
    int left = grid[i][j]+f(i,j-1,grid);
    return min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
   int n = grid.size();
   int m = grid[0].size();
  return f(n-1,m-1,grid);
}



// INT_MAX not giving right answer but 1e9 gives right answer why?


// Suppose INT_MAX is 2147483647, and the current cell value in the grid is 100.
 When you add grid[i][j] + f(i - 1, j, grid), it will be 2147483747, which exceeds INT_MAX and wraps around to -2147483549 (assuming a 32-bit int).
 Consequently, the function may incorrectly consider this negative value as the minimum sum.



Time Complexity:   O(2^(N*M))
Space Complexity:  O(N-1)+O(M-1)     where (N-1)+(M-1) is path length









#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i==0&&j==0)return grid[i][j];
    if(i<0||j<0)return 1e9 ;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = grid[i][j]+f(i-1,j,grid,dp);
    int left = grid[i][j]+f(i,j-1,grid,dp);
    dp[i][j]= min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
  return f(n-1,m-1,grid,dp);
}





Time Complexity:   O(N*M)
Space Complexity:  O(N-1)+O(M-1)+ O(N*M)       where (N-1)+(M-1) is path length







#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
   int n = grid.size();
   int m = grid[0].size();
   int dp[n][m];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == 0 && j == 0)dp[i][j] = grid[i][j];
          else {
            int up = grid[i][j] , left = grid[i][j];

            if (i > 0)

// requiring  previous row's j column

               up += dp[i - 1][j];
            else {
              up += 1e9;
            }
            if (j > 0)

// current row's j-1 column

              left += dp[i][j-1];
            else {
              left += 1e9;
            }
            dp[i][j] = min(up , left);
          }
        }
  }
        return dp[n-1][m-1];
}





Time Complexity:   O(N*M)
Space Complexity:  O(N-1)+O(M-1)     where (N-1)+(M-1) is path length   







#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
   int n = grid.size();
   int m = grid[0].size();
   vector<int>prev(m,0);
	for (int i = 0; i < n; i++) {
    vector<int>curr(m,0);
        for (int j = 0; j < m; j++) {
          if (i == 0 && j == 0)curr[j] = grid[i][j];
          else {
            int up = grid[i][j] , left = grid[i][j];

            if (i > 0)
               up += prev[j];
            else {
              up += 1e9;
            }
            if (j > 0)
              left += curr[j-1];
            else {
              left += 1e9;
            }
            curr[j] = min(up , left);
          }
        }
        prev = curr;
  }
        return prev[m-1];
}





Time Complexity:   O(N*M)
Space Complexity:  O(M)
