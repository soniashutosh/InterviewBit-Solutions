vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    if(n==0) {
        return {};
    }
    int maxI = -1, maxJ = -1; // for storing max start and end encountered till current subarray
    int i = 0, j = 1; // used to maintain current window
    long long  currSum = A[0], maxSum = 0; // stores currSum and maxSum encountered at that point...
    
    while(i<n and j<n) {
        if(A[j] + currSum >= currSum and currSum >= 0) { // valid condition to increase our window
            currSum += A[j];
            j++;
        }
        else if(currSum>=0){ // update current window and update if okay to update ans
            if(maxI != -1) {
                if((maxSum < currSum) or (maxSum==currSum and (j-i > maxJ- maxI))) {
                    maxI = i;
                    maxJ = j;
                }
            }
            else {
                maxI = i;
                maxJ = j;
            }
            maxSum = max(currSum, maxSum);
            i = j;
            currSum = A[j];
            j++;
        }
        else { // ignore negative numbers ...
            i = j;
            currSum = A[j];
            j++;
        }
    }
    
    // for last window update indexes if needed...
    if(currSum >= 0) {
        if(maxI != -1) {
            if((maxSum < currSum) or (maxSum==currSum and (j-i > maxJ- maxI))) {
                maxI = i;
                maxJ = j;
            }
        }
        else {
            maxI = i;
            maxJ = j;
        }
    }
    
    // store element of current window in array and return ....
    vector<int> res;
    if(maxI != -1) {
        for(int i=maxI;i<maxJ;i++) {
            res.push_back(A[i]);
        }
    }
    return res;
}
