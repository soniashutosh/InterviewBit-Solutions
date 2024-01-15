string Solution::longestCommonPrefix(vector<string> &A) {
    string preFix = "";
    int preCount = 0;
    bool loopAgain = true;
    bool thisCharIsOK = false;
    
    //this will break as soon as a difference in prefix is found
    while(loopAgain)
    {
    	if(preCount >= A[0].length())
    	break;
        char a = A[0][preCount];
        thisCharIsOK = true;
        
        for(int i=1;i<A.size();i++)
        {
            if(preCount > A[i].length())
            {
                thisCharIsOK = false;
                break;
            }
            if(A[i][preCount]!=a)
            {
                thisCharIsOK = false;
                break;
            }
        }
        
        if(thisCharIsOK == false)
        {
            break;
        }
        else
        {
            preFix += a;
            preCount++;
        }
    }
    return preFix;
}