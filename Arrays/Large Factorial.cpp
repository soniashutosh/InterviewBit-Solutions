string add(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    string res = "";
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    
    int i = 0, sum = 0, carry = 0;
    while(i<min(n1,n2)) {
        int a = str1[i]-'0', b = str2[i]-'0';
        sum = (a+b+carry)%10;
        carry = (a+b+carry)/10;
        res += to_string(sum);
        i++;
    }
    
    if(n1 > n2) {
        while(i<n1) {
            int a = str1[i]-'0';
            sum = (a+carry)%10;
            carry = (a+carry)/10;
            res += to_string(sum);
            i++;
        }
    }
    else {
        while(i<n2) {
            int b = str2[i]-'0';
            sum = (b+carry)%10;
            carry = (b+carry)/10;
            res += to_string(sum);
            i++;
        }
    }
    
    if(carry) {
        res += "1";
    }
    
    reverse(res.begin(), res.end());
    return res;
}

string multiplyString(string str, int n) {
    string res = "";
    reverse(str.begin(),str.end());
    
    int carry = 0;
    for(int i=0;i<str.size();i++) {
        int t = str[i] -'0';
        int prod = t*n;
        int n = (prod+carry)%10;
        carry =  (prod+carry)/10;
        
        res += to_string(n);
    }
    
    if(carry > 0) {
        string t = to_string(carry);
        res += t;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    string res = "";
    
    for(int i = n1-1;i>=0;i--) {
        string t = multiplyString(str2, str1[i]-'0');
        int j = (n1-1)-i;
        while(j--) {
            t += "0";
        }
        res = add(res, t);
    }
    
    return res;
}

string Solution::solve(int A) {
    string res = "1";
    for(int i=2;i<=A;i++) {
        res = multiply(res, to_string(i));
    }
    return res;
}
