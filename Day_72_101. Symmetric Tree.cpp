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
    bool dfs( TreeNode* a , TreeNode* b ){
        if( ( (a == NULL) != ( b == NULL ) ) || ( (a != NULL) && a->val != b->val) ) return 0 ;
        if( a == b && a == NULL ) return 1;
        return dfs( a->left  , b->right ) && dfs( a->right  , b->left ) ; 
    }
    bool isSymmetric(TreeNode* root) {
        // if ( root == NULL ) return 0 ; [ in case no provided nodes in some versions ]
        return dfs(root->left,root->right);
    }
};
