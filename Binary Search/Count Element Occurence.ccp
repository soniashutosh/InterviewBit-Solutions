int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    if(n==0) return 0;
    
    int start = 0;
    int lo = 0, hi = n-1, mid;
    
    // Find first index where element lies
    // Predicate (A[mid] < B) -> T*F* and check for first F
    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        if(A[mid] < B) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    // check for that case when element itself is not present in array
    if(A[lo] != B) {
        return 0;
    }
    start = lo;
    
    // find last index where element lies 
    // Predicate (A[mid] <= B) -> T*F* and check for last T
    lo = 0, hi = n-1;
    while(lo<hi) {
        mid = lo + (hi-lo+1)/2;
        if(A[mid] <= B) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    
    return (lo - start + 1);
}
