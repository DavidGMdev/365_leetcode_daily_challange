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
    int mx = 0;
    pair<int,int> rec( TreeNode* node ){
        if( node == NULL ) return { 0,0 };
        pair<int,int> ret = {0 , 0};
        auto p1 = rec( node -> left );
        auto p2 = rec( node -> right );
        if ( node -> left != NULL ) ret.first = p1.second + 1 ;
        if ( node-> right != NULL ) ret.second = p2.first + 1;
        mx = max({mx,ret.first, ret.second });
        return ret ;
    }
    int longestZigZag(TreeNode* root) {
        rec(root);
        return mx;
    }
};
