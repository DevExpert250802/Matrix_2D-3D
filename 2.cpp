

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
bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
                if(arr[i][0]<=target && target<=arr[i][m-1] ){
                        return binarySearch(arr[i],target);
                }
        }
        return false; 
}











bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();

        int low=0, high=n*m-1;
        while(low<=high){
          int mid =(low+high)/2;
          int row=mid/m , col=mid%m;
          if(arr[row][col]==target) return true;
          else if (arr[row][col]<target)low=mid+1;
           else high=mid-1;
        }     
        return false; 
}
