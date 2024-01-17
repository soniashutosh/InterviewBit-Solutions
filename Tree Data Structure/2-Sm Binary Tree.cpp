/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode* root, int B, unordered_map<int, vector<TreeNode*>> &mp, bool &ans) {
    if(!root) {
        return;
    }
    // insert value while traversing
    mp[root->val].push_back(root);
    helper(root->left, B, mp, ans);
    helper(root->right, B, mp, ans);
    
    if(mp.find(B-root->val) != mp.end()) {
        // if root->val is half of that number we need to check number of times that number is present in BT.
        // if its greater than 2 then okay
        if(root->val == B-root->val) {
            ans = ans or mp[root->val].size() == 2;
        }
        // otherwise we get our ans....
        else {
            ans = true;
        }
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    bool ans = false;
    // stores value present at which node pointer 
    // for handling scerarios of same number sums to B we had taken vector ...
    unordered_map<int, vector<TreeNode*>> mp;
    helper(A, B, mp, ans);
    return ans;
}
