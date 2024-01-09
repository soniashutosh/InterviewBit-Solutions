
int LCS(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    // dp[i][j] = number of subsequences for s1(0...i) of making with s2(0..j)
    vector<vector<int>> dp(n1+1,vector<int> (n2+1, 0));
    
    for(int j=0;j<=n1;j++) {
        dp[j][0] = 1;
    }
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
                dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n1][n2];
}

int Solution::numDistinct(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    int res = LCS(str1, str2);
    return res; 
    
}
