int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(n==0) return 0;
    /*
        Predicate: A[mid] <= B => T*F*
        we are searching for last T so it will be taken into account 
        so updated lo -> mid and hi -> mid - 1 as we can ignore that number
    */
    int lo = 0, hi = n-1;
    while(lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        
        if(A[mid] <= B) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    if(A[lo] > B)
        return 0;
    return lo + 1;
}
