// using heap

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    priority_queue<int,vector<int>, greater<int>> pq;
    int a = min(A,min(B,C));
    int c = max(A,max(B,C));
    int b = A^B^C^a^c;
    
    int count = -1;
    // for taking care of duplicates ....
    if(a==b and b==c) {
        count = 3;
        pq.push(a);
    }
    else if(a==b) {
        count == 2;
        pq.push(a);
        pq.push(c);
    }
    else if(b==c) {
        count = 2;
        pq.push(a);
        pq.push(b);
    }
    else {
        pq.push(A);
        pq.push(B);
        pq.push(C);
    }
    
    // populate ith element on the goy using heap
    while(D--) {
        auto t = pq.top();
        res.push_back(t);
        pq.pop();
        
        if(count == 3) {
            pq.push(t*c);
        }
        else if(count == 2) {
            if(a==b) {
                if(t%c==0) {
                    pq.push(t*c);
                }
                else {
                    pq.push(t*b);
                    pq.push(t*c);
                }
            }
            else if(b==c) {
                if(t%c==0) {
                    pq.push(t*c);
                }
                else {
                    pq.push(t*a);
                    pq.push(t*b);
                }
            }
        }
        else {
            if(t%c==0) {
                pq.push(t*c);
            }
            else if(t%b==0) {
                pq.push(t*b);
                pq.push(t*c);
            }
            else {
                pq.push(t*a);
                pq.push(t*b);
                pq.push(t*c);
            }
        }
    }
    
    return res;
}
