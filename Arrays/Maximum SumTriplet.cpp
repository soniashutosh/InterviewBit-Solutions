int getLeftVal(set<int>& leftMin, int& key){
    auto it = leftMin.lower_bound(key);
    --it;
    return (*it);
}

int Solution::solve(vector<int> &a) {
    int ans = 0;
    int n = a.size();
   
    // get rightmax value for each position
    vector<int> rightMax(n+1);
    rightMax[n] = 0;
    for(int i = n-1; i >= 0; --i){
        rightMax[i] = max(a[i], rightMax[i+1]);
    }
    set<int> leftMin;
    leftMin.insert(INT_MIN);
   
    for(int i = 0; i < n-1; i++){
        if(a[i] < rightMax[i+1]){
            int leftVal = getLeftVal(leftMin, a[i]);
            int currSum = leftVal + a[i] + rightMax[i+1];
            ans = max(ans, currSum);
            leftMin.insert(a[i]);
        }
    }
   
    return ans;
}