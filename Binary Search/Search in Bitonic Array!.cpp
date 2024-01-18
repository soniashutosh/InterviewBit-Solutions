int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(n==0) return -1;
    
    /* find the breakPoint predicate used: 
        A[mid] < A[mid+1] => T*F* 
        we are finding last T index here 
        [3, 9, 10, 20, 17, 5, 1] => we are targeting to find index of 20 i.e. 4
    */
    int lo = 0, hi = n-1;
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        
        if(A[mid] < A[mid+1]) {
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }

    int breakPoint = lo;
    
    // first binary search in sorted increasing array for number B
    lo = 0, hi = breakPoint;
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(A[mid] < B) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    // if we find that number return the index ...
    if(A[lo] == B) {
        return lo;
    }
    
    // second binary search in sorted decreasing array for number B
    lo = breakPoint+1, hi = n-1;
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(A[mid] > B) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    // if we find that number return the index ....
    if(A[lo] == B) {
        return lo;
    }
    
    // if not able to find the number return -1
    return -1;
}
