/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *root, int &B, int &prev, TreeNode* &res) {
    if(root->left) {
        helper(root->left, B, prev, res);
    }
    if(prev == B) {
        res = root;
    }
    prev = root->val;
    if(root->right) {
        helper(root->right, B, prev, res);
    }
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    if(A==NULL) {
        return A;
    }
    TreeNode *res = NULL;
    int prev = -1;
    helper(A,B,prev,res);
    return res;
}
