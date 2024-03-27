
/* Minimum path sum in Triangular Grid :


We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.

At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘) */





//Recursion




#include <bits/stdc++.h>
 int f(int i, int j,vector<vector<int>>&a, int n){
  if(i==n-1)return a[n-1][j];
  int down = a[i][j] + f(i+1,j,a,n);
  int diagonal = a[i][j] + f(i+1,j+1,a,n);
  return min(down,diagonal);
}
int minimumPathSum(vector<vector<int>>&triangle, int n){
  return f(0,0,triangle,n);
}




//Time Complexity:   O(2^N)
//Space Complexity:  O(N)




  
//Memorization




#include <bits/stdc++.h>
 int f(int i, int j,vector<vector<int>>&a, int n,vector<vector<int>>&dp){
  if(i==n-1)return a[n-1][j];
  if(dp[i][j]!=-1) return dp[i][j];
  int down = a[i][j] + f(i+1,j,a,n,dp);
  int diagonal = a[i][j] + f(i+1,j+1,a,n,dp);
  return min(down,diagonal);
}
int minimumPathSum(vector<vector<int>>&triangle, int n){
  vector<vector<int>>dp(n,vector<int>(n,-1));
  return f(0,0,triangle,n,dp);
}






//Time Complexity:   O(N*N)
//Space Complexity:  O(N*N)+ O(N)     




  


//Tabulation



#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>&triangle, int n){
  vector<vector<int>>dp(n,vector<int>(n,0));
   for(int j=0;j<n;j++){
  dp[n-1][j]=triangle[n-1][j];
}
int down,diagonal=0;
for (int i=n-2; i>=0; i--) {
  for (int j=i; j>=0; j--) {
    int down = triangle[i][j] + dp[i+1][j];
    int diagonal = triangle[i][j] + dp[i+1][j+1];
    dp[i][j] = min(down,diagonal);
  }
}
return dp[0][0];
}




//Time Complexity:   O(N*N)
//Space Complexity:  O(N*N) 




//Space Optimization




#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>&triangle, int n){
  vector<int>front(n,0) ,curr(n,0);
   for(int j=0;j<n;j++){
  front[j]=triangle[n-1][j];
}
int down,diagonal=0;
for (int i=n-2; i>=0; i--) {
  for (int j=i; j>=0; j--) {
    int down = triangle[i][j] + front[j];
    int diagonal = triangle[i][j] + front[j+1];
    curr[j] = min(down,diagonal);
  }
  front = curr;
}
return front[0];
}





//Time Complexity:   O(N*N)
//Space Complexity:  O(2N) 







//More Space Optimized



int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> front(n, 0);

    for (int j = 0; j < n; j++) front[j] = triangle[n - 1][j];
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <=i; j++) {
            front[j] = min(front[j], front[j + 1])+triangle[i][j];
        }
    }
    return front[0];
}




//Time Complexity:   O(N*N)
//Space Complexity:  O(N) 

