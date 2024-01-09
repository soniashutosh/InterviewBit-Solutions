int LCS(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1, 0));
    
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(s1[i-1]==s2[j-1] and (i!=j)) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}

int Solution::anytwo(string str) {
    int n = str.size();
    if(n<=2) return 0;
    
    
    int t1 = LCS(str,str);
    if(t1>=2) {
        return 1;
    }
    return 0;
}
