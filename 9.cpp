Median in a row-wise sorted Matrix



int median(vector<vector<int>> &matrix, int m, int n) {
  vector<int> arr;
  
  //flatten the 2D matrix into a 1D Array as show below:
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      arr.push_back(matrix[i][j]);
    }
  }
  sort(arr.begin(), arr.end());
  return arr[m*n/2];
}

