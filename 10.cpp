int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;
    //traverse the rows:
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=matrix[i][j];
            if(cnt>cnt_max){
               cnt_max = cnt;
               index = i;
            }
        }
    }
    return index;
}



Time Complexity: O(n X m)

Space Complexity: O(1) 









int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}





Time Complexity: O(n X logm) 

Space Complexity: O(1) 
