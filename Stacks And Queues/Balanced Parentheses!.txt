int Solution::solve(string A) {
    int n = A.size();
    if(n==0) return 1;
    
    stack<int> st;
    for(int i=0;i<n;i++) {
        if(A[i]=='(') {
            st.push(i);
        }
        else {
            if(st.empty()) {
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty())
        return 1;
    return 0;
}
