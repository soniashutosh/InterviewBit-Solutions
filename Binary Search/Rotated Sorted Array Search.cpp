// simple binary search function to find element in range of lo to hi
int binarySearch(const vector<int> &A, int lo, int hi, int B) {
    if(lo == hi) {
        return lo;
    }
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(A[mid] < B) {
            lo = mid +1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    if(n==0) 
        return 0;
        
    int lo = 0, hi = n - 1;
    
    // search for the rotation point 
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(A[mid] >= A[0]) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    int breakPoint = lo, t1; // find breakPoint i.e. index of smaller number in array
    if (A[0] <= B and A[breakPoint-1] >= B) {
        t1 = binarySearch(A, 0, breakPoint-1, B);
        if(A[t1] == B) {
            return t1;
        }
    }
    else {
        t1 = binarySearch(A, breakPoint, n-1, B);
        if(A[t1] == B) {
            return t1;
        }
    }
    return -1;
}
