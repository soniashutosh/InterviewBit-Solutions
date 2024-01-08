string Solution::serialize(vector<string> &A) {
    string res="";
    for(int i=0;i<A.size();i++){
        res+=A[i];
        res+=to_string(A[i].size());
        res+="~";
    }
    return res;
}
