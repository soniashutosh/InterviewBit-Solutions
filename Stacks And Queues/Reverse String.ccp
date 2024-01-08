// 1. Solution without Stack
string Solution::reverseString(string A) {
    reverse(A.begin(), A.end());
    
    return A;
}

// 2. With Stack
string Solution::reverseString(string A) {
    string res = "";
    int n = A.size();
    if(n==0) return res;
    
    stack<char> st;
    for(int i=0;i<n;i++) {
        st.push(A[i]);
    }
    
    while(!st.empty()) {
        auto t = st.top();
        st.pop();
        res += t;
    }
    
    return res;
}
