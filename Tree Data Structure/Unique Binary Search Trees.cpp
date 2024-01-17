/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> makeTrees(int start, int root, int end) {
    vector<TreeNode*> left, right;
    
    // get all possible subtrees for left side
    if(start < root) {
        for(int i=start;i<root;i++) {
            auto t = makeTrees(start, i, root-1);
            for(auto ele: t) {
                left.push_back(ele);
            }
        }
    }
    else {
        // for taking care of root always append null to it...
        left.push_back(NULL);
    }
    
    // get all possible subtrees for right side
    if(root < end) {
        for(int i=root+1;i<=end;i++) {
            auto t = makeTrees(root+1, i, end);
            for(auto ele: t) {
                right.push_back(ele);
            }
        }
    }
    else {
        // for taking care of root always append null to it...
        right.push_back(NULL);
    }
    
    vector<TreeNode*> res;
    // Make all possible trees for this scenario using all combinations ....
    for(auto l: left) {
        for(auto r: right) {
            TreeNode* treeRoot = new TreeNode(root);
            treeRoot->left = l;
            treeRoot->right = r;
            res.push_back(treeRoot);
        }
    }
    return res;
}

vector<TreeNode*> Solution::generateTrees(int A) {
    vector<TreeNode*> res;
    
    for(int i=1;i<=A;i++) {
        // makeTrees method take start index, root and end index and give all possible bst's
        auto t = makeTrees(1, i, A);
        for(auto ele: t) {
            res.push_back(ele);
        }
    }
    return res;
}
