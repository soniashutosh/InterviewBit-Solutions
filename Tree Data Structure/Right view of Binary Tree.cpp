/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    if(A == NULL) {
        return res;
    }
    
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i<n; i++) {
            auto t = q.front();
            q.pop();
            if(t->left != NULL) q.push(t->left);
            if(t->right != NULL) q.push(t->right);
            
            if(i==n-1) {
                res.push_back(t->val);
            }
        }
    }
    return res;
}
