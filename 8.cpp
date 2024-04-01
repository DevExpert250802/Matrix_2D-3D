Rotate The Matrix ( 90 degree )




void rotateMatrix(vector<vector<int>> &mat){
	int n=mat.size();
	vector<vector<int>>ans(n, vector<int>(n, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[j][n-i-1]=mat[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=ans[i][j];
		}
	}
	
}




T.C. = O(N)*O(N) + O(N)*O(N)

S.C. = O(N) * O(N) 







void rotateMatrix(vector<vector<int>> &mat){
	int n=mat.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}



T.C.= O(N) * O(N/2) + O(N) * O(N/2)

S.C.=O(1)
