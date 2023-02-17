/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev = INT_MIN;
    int ans = INT_MAX;
    void dfs(TreeNode* node){
        if ( node == NULL ) return;
        dfs(node->left);
        if(prev != INT_MIN) ans = min(ans,node->val-prev);
        prev = node->val;
        dfs(node->right);
        
    }
    int minDiffInBST(TreeNode* root) {
      dfs(root);
        return ans;
    }
};
