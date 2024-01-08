vector<string> Solution::deserialize(string A) {
    vector<string> res;
    string str="";
    for(int i=0;i<A.length();i++){
        if(A[i]=='~'){   
            res.push_back(str);
            str="";
        }
        else if(A[i]<'0'|| A[i]>'9'){
            str+=A[i];
        }
    }
    return res;
}

