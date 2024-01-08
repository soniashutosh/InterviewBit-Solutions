int Solution::solve(string A, string B) {
    int n = A.size(), m = B.size();
    if(n==0 or m ==0) return 0;
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}
