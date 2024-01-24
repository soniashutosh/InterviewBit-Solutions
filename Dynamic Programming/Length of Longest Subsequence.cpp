int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n<=1) return n; 
    vector<vector<int>> dp(n+1, vector<int>(2,0));
    int res = 1;
    // longest increasing subsequence ending at that index excluding that element
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(A[j] < A[i]) {
                dp[i+1][0] = max(1, max(dp[i+1][0], dp[j+1][0]+1));
            }
        }
    }
    // longest decreasing subsequence ending at that index excluding that element
    for(int i=n-1;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            if(A[i] > A[j]) {
                dp[i+1][1] = max(1, max(dp[i+1][1], dp[j+1][1]+1));
            }
        }
        // update res to longestIncreasingSubsequence + longestDecreasingSubsequence + 1 for aby index.
        res = max(res, dp[i+1][0] + dp[i+1][1] + 1);
    }
    return res;
}

