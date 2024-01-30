/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode* root, int currSum, int &totalSum, int &res) {
    if(!root) {
        return;
    }
    currSum += root->val;
    if(!root->left and !root->right and currSum == totalSum) {
        res = 1;
    }
    helper(root->left, currSum,totalSum, res);
    helper(root->right, currSum, totalSum, res);
} 

int Solution::hasPathSum(TreeNode* root, int B) {
    if(!root) return 0;
    int currSum = 0;
    int res = 0;
    helper(root, currSum, B, res);
    return res;
}

// ----------------------------------------------------------
// Solution 2


int Solution::hasPathSum(TreeNode* root, int B) {
    if(!root) {
        return 0;
    }
    B -= root->val;
    if(!root->left and !root->right and B==0) {
        return 1;
    } 
    
    return max(hasPathSum(root->left, B), hasPathSum(root->right, B));
}