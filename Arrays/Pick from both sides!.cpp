int Solution::solve(vector<int> &A, int B) {
    long long n = A.size(), res;
    
    // Base Case
    if(n <= B) {
        for(int i=0;i<n;i++) {
            res += A[i];
        }
        return res;
    }
    
    // Include first B elements
    long long curr = 0, i;
    for(i=0;i<B;i++) {
        curr += A[i];
    }
    res = curr;
    
    i--; // Adjust pointer to current index...
    
    // Try removing one by one element from last and add element form last ....
    int j=n-1;
    while(B--) {
        curr += A[j] - A[i];
        res = max(res, curr);
        i--;
        j--;
    }
    
    return res;
}
