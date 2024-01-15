void makeBST(vector<int>& A, int &index, int low, int high){
    if(index >= A.size()) 
        return;
    if(A[index] <= low || A[index] >= high) 
        return;
    int root = A[index];
    index++;
    makeBST(A, index, low, root); 
    makeBST(A, index, root, high); 
}

int Solution::solve(vector<int> &A) {
    int index = 0;
    int low = INT_MIN;
    int high = INT_MAX;
    makeBST(A, index, low, high);
    if(index < A.size()) 
        return false;

    return true;

}