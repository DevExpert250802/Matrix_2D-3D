Search In A 2D Matrix II


Search in a row and column-wise sorted matrix





    vector<int> searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(arr[i][j]==target) return {i,j};
           }
        }
    return {-1,-1}; 
}








int binarySearch(vector<int>& arr1, int target) {
    int n = arr1.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid =(high + low) / 2; // to avoid integer overflow
        if (arr1[mid] == target)
            return mid; // return the index directly
        else if (arr1[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

vector<int>searchMatrix(vector<vector<int>>& arr, int target) {
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++) {
        int ind = binarySearch(arr[i], target);
        if (ind != -1) {
            return {i, ind}; 
        }
    }
    return {-1, -1};
}









    vector<int> searchMatrix(vector<vector<int>>&matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return {row,col};
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return {-1, -1};
}
