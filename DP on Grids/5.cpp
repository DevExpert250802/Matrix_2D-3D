  /*      Minimum/Maximum Falling Path Sum
We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.
At every cell we can move in three directions: to the bottom cell (↓),   to the bottom-right cell(↘),   or to the bottom-left cell(↙). */







#include <bits/stdc++.h> 
 int f(int i,int j,vector<vector<int>>&a){
    if ( j < 0 || j >= a[0].size()) return -1e9;
     if(i==0) return a[0][j];
     int up        = a[i][j] + f(i-1,j,a);
     int Rdiagonal = a[i][j] + f(i-1,j+1,a);
     int Ldiagonal = a[i][j] + f(i-1,j-1,a);
     
      return max(up, max(Rdiagonal, Ldiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
   int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    for(int j=0; j<m;j++){
     maxi = max (maxi,f(n-1,j,matrix));
}
return maxi;
}



Time Complexity:   O(m*(3^n))
Space Complexity:  O(N)





#include <bits/stdc++.h> 
 int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
    if ( j < 0 || j >= a[0].size()) return -1e9;
     if(i==0) return a[0][j];
      if(dp[i][j]!=-1) return dp[i][j];
     int up        = a[i][j] + f(i-1,j,a,dp);
     int Rdiagonal = a[i][j] + f(i-1,j+1,a,dp);
     int Ldiagonal = a[i][j] + f(i-1,j-1,a,dp);
     
      return dp[i][j]= max(up, max(Rdiagonal, Ldiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
   int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi = -1e9;
    for(int j=0; j<m;j++){
     maxi = max (maxi,f(n-1,j,matrix,dp));
}
return maxi;
}




Time Complexity:   O(N*M)
Space Complexity:  O(N*M) + O(N)





#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
   int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
  for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }

    int maxi = -1e9;
    for(int j=0; j<m;j++){
     maxi = max(maxi,dp[n-1][j]);
}
return maxi;
}







Time Complexity:   O(N*M)
Space Complexity:  O(N*M)








#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
   int n = matrix.size();
    int m = matrix[0].size();
    vector<int>prev(m,0),curr(m,0);
        for(int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }
  for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            curr[j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
       prev=curr;
    }

    int maxi = -1e9;
    for(int j=0; j<m;j++){
     maxi = max(maxi,prev[j]);
}
return maxi;
}





Time Complexity:   O(N*M)
Space Complexity:  O(M)





#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){

            int up = matrix[i][j] + matrix[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += matrix[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += matrix[i-1][j+1];
            else rightDiagonal += -1e9;
            
            matrix[i][j]= max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    int maxi = -1e9;
    for(int j=0; j<m;j++){
        maxi = max(maxi,matrix[n-1][j]);
    }
return maxi;
}




Time Complexity:   O(N*M)
Space Complexity:  O(1)
  
