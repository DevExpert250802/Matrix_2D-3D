Search In A 2D Matrix II


Search in a row and column-wise sorted matrix




    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(arr[i][j]==target) return true;
           }
        }
    return false; 
}











bool binarySearch(vector<int>&arr1, int target) {
        int n=arr1.size();
        int low=0, high=n-1;
        while(low<=high){
           int mid = (low+high)/2;
           if(arr1[mid]==target) return true;
           else if (arr1[mid]<target)low=mid+1;
           else high=mid-1;
        }
        return false;
}
bool searchMatrix(vector<vector<int>>&arr, int target) {
       int n=arr.size();
       int m=arr[0].size();
       for(int i=0;i<n;i++){
           bool flag = binarySearch(arr[i],target);
           if(flag==true) return true;
       }
       return false; 
}







    bool searchMatrix(vector<vector<int>>&matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}
