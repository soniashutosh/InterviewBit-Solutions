string Solution::solve(string A, string B) {
    int n = A.size();
    int bulls = 0, cows = 0;
    unordered_map<char,int> mp;
    vector<int> t;
    
    for(int i=0;i<n;i++) {
        // Get bulls and store left element of A and B
        if(A[i]==B[i]) {
            bulls++;
        }
        else {
            mp[A[i]]++;
            t.push_back(i);
        }
    }
    
    // check left element of B if they are present in A
    for(auto ele: t) {
        if(mp.find(B[ele]) != mp.end()) {
            cows++;
            mp[B[ele]]--;
            if(mp[B[ele]] == 0) {
                mp.erase(B[ele]);
            }
        }
    }
    
    return to_string(bulls)+"A"+to_string(cows)+"B";
}
