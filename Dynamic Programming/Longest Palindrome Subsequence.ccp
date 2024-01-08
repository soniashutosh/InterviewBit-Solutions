int Solution::solve(string A) {
    int n = A.size();
    if(n==0) return 0;
    
    vector<vector<int>> dp(n,vector<int> (n,0));
    // definition dp[i][j] -> maximum palindrome length starting from index i to j in string 
    // if characters are equal then length = 2 + (length of max palindrome starting from i+1..j-1) else it will be maximum of i to j-1 or i+1 to j 
    
    // Base case 
    // all palindromes of length one 
    for(int i=0;i<n;i++) {
        dp[i][i] = 1;
    }
    
    int res = 1;
    for(int i=2;i<=n;i++) {
        for(int j=0;i+j-1<n;j++) {
            if(A[j]==A[i+j-1]) {
                dp[j][i+j-1] = 2 + dp[j+1][i+j-2];
            }
            else {
                dp[j][i+j-1] = max(dp[j+1][i+j-1],dp[j][i+j-2]);
            }
            res = max(res, dp[j][i+j-1]);
        }
    }
    return res;
}
