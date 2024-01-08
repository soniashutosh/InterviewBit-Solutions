int Solution::isValid(string str) {
    int n = str.size();
    stack<char> st;
    for(int i=0;i<n;i++) {
        // for open parenthesis just push on stack
        if(str[i]=='(' or str[i]=='{' or str[i]=='[') {
            st.push(str[i]);
        }
        // for closing brackets check for last opening brackets
        else if(str[i] == ')') {
            if(!st.empty() and st.top() == '(') {
                st.pop();
            }
            else 
                return 0;
        }
        else if(str[i] =='}') {
            if(!st.empty() and st.top() == '{') {
                st.pop();
            }
            else 
                return 0;
        }
        else if(str[i] ==']') {
            if(!st.empty() and st.top() == '[') {
                st.pop();
            }
            else 
                return 0;
        }
    }
    // if stack size is not zero then we have more open brackets then closing brackets
    if(!st.empty())
        return 0;
    return 1;
}
