int Solution::minDistance(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    // dp[i][j] = minimum number of operations to convert str1[0..i] to str2[0..j]
    
    // base case 
    // if str1 is empty we can only convert it to str2 by inserting all the characters
    for(int i=1;i<=n2;i++) {
        dp[0][i] = i;
    }
    // if str2 is empty we can only convert it to str1 by deleting all the characters
    for(int i=1;i<=n1;i++) {
        dp[i][0] = i;
    }
    
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(str1[i-1]==str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                // replace
                dp[i][j] = 1 + dp[i-1][j-1];
                
                // delete
                dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
                
                // insert
                dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
            }
        }
    }
    
    return dp[n1][n2];
}
