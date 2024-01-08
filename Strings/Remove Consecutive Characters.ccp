string Solution::solve(string A, int B) {
    int j=0;
    int n=A.size();
    string ans="";
    
    while(j<n)
    {
        int c=0;
        char x = A[j];
        string t="";
        while(j<n && A[j]==x)
        {
            c++;
            t+=x;
            j++;
        }
        
        if(c<B || c>B)
        ans += t;
        
    }
    
    return ans;
}
