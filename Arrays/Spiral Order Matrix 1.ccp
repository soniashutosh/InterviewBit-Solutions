vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) {
        return {};
    }
    int m = A[0].size();
    int i1=0, j1=0, i2 = n-1, j2 = m-1;
    vector<int> res;
    int count = 0;
    while(i1 <= i2 and j1<=j2) {
        int j, i;
        if(count%4 == 0) {
            j = j1;
            while(j<=j2 and j<m) {
                res.push_back(A[i1][j]);
                j++;
            }
            i1++;
        }
        else if(count%4==1) {
            i = i1;
            while(i <= i2 and i<n) {
                res.push_back(A[i][j2]);
                i++;
            }
            j2--;
        }
        else if(count%4==2) {
            j = j2;
            while(j>=j1 and j >= 0) {
                res.push_back(A[i2][j]);
                j--;
            }
            i2--;   
        }
        else {
            i = i2;
            while(i>=i1 and i>=0) {
                res.push_back(A[i][j1]);
                i--;
            }
            j1++;
        }
        count++;
    }
    
    return res;
}
