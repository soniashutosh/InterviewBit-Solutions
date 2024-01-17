/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *root, int B, priority_queue<int> &pq) {
    if(!root) {
        return;
    }
    pq.push(root->val);
    if(pq.size() > B) {
        // cout<<pq.top()<<" ";
        pq.pop();
    }
    helper(root->left, B, pq);
    helper(root->right, B, pq);
} 

int Solution::kthsmallest(TreeNode* A, int B) {
    // this will store min k elements found soo far
    priority_queue<int> pq;
    helper(A, B, pq);
    return pq.top();
}
