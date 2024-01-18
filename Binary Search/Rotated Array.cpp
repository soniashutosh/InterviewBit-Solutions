int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    if(n<=1) return n;
    
    int lo = 0, hi = n-1;
    
    while(lo<hi) {
        int mid = lo + (hi-lo)/2;
        
        if(A[mid] > A[mid+1]) {
            return A[mid+1];
        }
        
        if(A[mid] > A[lo]) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    
    return A[0];
}
