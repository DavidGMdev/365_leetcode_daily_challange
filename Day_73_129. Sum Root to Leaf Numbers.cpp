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
    int ans = 0 ;
    void dfs( TreeNode* node , int curr ){
        if ( node == NULL ) {
            return ;
        }
        curr *= 10 ; 
        curr += node->val ;
        if ( node-> left == NULL && node-> right == NULL ){
            ans += curr ;
            return;
        }
        else {
            dfs( node->left  , curr );
            dfs( node->right , curr );
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
