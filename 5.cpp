Transpose of a Matrix

N*M Matrix


vector<vector<int>> transpose(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size(); 
    vector<vector<int>> b(m, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            b[j][i] = mat[i][j];
        }
    }
    return b;
}



N*N Matrix


vector<vector<int>> transpose(vector<vector<int>> &mat){
       int n=mat.size();
       for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
       return mat;
  }
