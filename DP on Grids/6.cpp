3-d DP : Ninja and his friends



We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially,

Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: 
to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.

They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.







#include <bits/stdc++.h> 
int f(int i,int j1,int j2,int r, int c, vector<vector<int>> &a){
// Base Condition Out of bound casees
if(j1<0 || j1>=c ||j2<0 || j2>=c) return -1e8;
// Base Condition when both reach end cell
if(i==r-1) {
    if(j1==j2) return a[i][j1];
     else return a[i][j1]+a[i][j2];
}
// explore all the paths
int maxi = -1e8;
for(int dj1=-1;dj1<=1;dj1++){
  for (int dj2 = -1; dj2 <= 1; dj2++) {
    int value = 0;
    if (j1 == j2)
      value = a[i][j1];
    else
      value = a[i][j1] + a[i][j2];
    value += f(i + 1, j1 + dj1, j2 + dj2, r, c, a);
    maxi = max(maxi, value);
  }
}
return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0,0,c-1,r,c,grid);
}





  Time Complexity    : O((3^N)*(3^N))
  Space Complexity   : O(N) 
  




#include <bits/stdc++.h> 
int f(int i,int j1,int j2,int r, int c, vector<vector<int>> &a,vector<vector<vector<int>>>&dp){
// Base Condition Out of bound casees
if(j1<0 || j1>=c ||j2<0 || j2>=c) return -1e8;
// Base Condition when both reach end cell
if(i==r-1) {
    if(j1==j2) return a[i][j1];
     else return a[i][j1]+a[i][j2];
}
if (dp[i][j1][j2]!=-1) return dp[i][j1][j2];

// explore all the paths
int maxi = -1e8;
for(int dj1=-1;dj1<=1;dj1++){
  for (int dj2 = -1; dj2 <= 1; dj2++) {
    int value = 0;
    if (j1 == j2)
      value = a[i][j1];
    else
      value = a[i][j1] + a[i][j2];
    value += f(i + 1, j1 + dj1, j2 + dj2, r, c, a,dp);
    maxi = max(maxi, value);
  }
}
return dp[i][j1][j2]= maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // int dp [r][c][c];
vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,r,c,grid,dp);
}






  Time Complexity    : O(N*M*M)*9
  Space Complexity   : O(N) + O(N*M*M)
  





#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // int dp [r][c][c];
vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
 for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c- 1];
}





  Time Complexity    : O(N*M*M)*9
  Space Complexity   : O(N*M*M) 
  






#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // int dp [r][c][c];
vector < vector < int >> front(c, vector < int > (c, 0)), cur(c, vector < int > (c, 0));
 for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += front[j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][c- 1];
}





  Time Complexity    : O(N*M*M)*9
  Space Complexity   :   O(M*M)
