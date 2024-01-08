int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    long long n = A.size(), res = 0;
    
    // Base Case
    if(n<=1) return res;
    
    for(int i=1;i<n;i++) {
        int x_diff = abs(A[i]-A[i-1]), y_diff = abs(B[i]-B[i-1]);
        /*
            First move diagonally till both the difference are 0 and then move either x or y axis direction whichever remains.
        */
        res += max(x_diff, y_diff);
    }
    
    return res;    
}
