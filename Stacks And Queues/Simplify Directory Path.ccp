//1. Working Solution

string Solution::simplifyPath(string path) {
    vector<string>   nameVect;
    string name;

    path.push_back('/');

    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
            if (name.size() == 0) continue;
            if (name == "..") {     //special case 1：double dot，pop dir
                if (nameVect.size() > 0) nameVect.pop_back();
            } else if (name == ".") {//special case 2:singel dot，don`t push
            } else {          
                nameVect.push_back(name);
            }
            name.clear();
        } else {
            name.push_back(path[i]);//record the name
        }
    }

    string result;
    if (nameVect.empty()) return "/";
    for (int i = 0; i < nameVect.size(); i++) {
        result.append("/" + nameVect[i]);
    }
    return result;
}


//2. Easy Solution
// getting TLE may be because of stringstream which is used for split string with delimeter as /

string Solution::simplifyPath(string path) {
    string res,temp;
    stack<string> s;
    stringstream ss(path);
    while(getline(ss,temp,'/')){
        if(temp=="." or temp=="")
            continue;
        if(temp==".." and !s.empty())
            s.pop();
        else if(temp!="..")
            s.push(temp);
    }
    
    while(!s.empty()){
        res="/" + s.top() + res;
        s.pop();
    }
    
    return res=="" ? "/" : res ;
}
