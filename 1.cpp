Print Pascal’s Triangle


1
1 1
1 2 1
1 3 3 1
1 4 6 4 1








Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.


We have an easier formula to find out the element i.e. r-1 C c-1. Let’s try to analyze the formula to find the value of the combination assuming r-1 as n and c-1 as r:


nCr = n! / (r! * (n-r)!)





int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r-1,c-1);
    return element;
}





Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.



void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}





Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.




vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>>triangle;
    for(int row=1;row<=N;row++){
        long long ans=1;
        vector<int>eachrow;
        eachrow.push_back(1);
        for(int column=1;column<row;column++){
            ans= ans*(row-column);
            ans=ans/column;
            eachrow.push_back(ans);
        }
        triangle.push_back(eachrow);
    }
    return triangle;
}

