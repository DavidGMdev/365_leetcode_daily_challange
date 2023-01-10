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

// #########################################################################
// solution 1 : multi dfs on both trees in same time and accmulate results 
// #########################################################################


// when guranteed false ?
// = one tree reach null mark before the other one
// = non-null node has diffrent values 

// when guranteed true ( for whole path ) ?
// = both reach null at the same time [ reaching this point means having same tree all long the path ]

// take care : 
// having same value not gurantee to return true for the whole path and stop recursive calls 


class Solution {
public:
    bool dfs( TreeNode* a , TreeNode* b ) {
        if ( (a == NULL || b == NULL) && a != b ) return false ;
        if ( (a == NULL || b == NULL) && a == b ) return true ;
        if ( a->val != b->val )  return false;   
        return ( dfs( a->left , b->left ) && dfs( a->right , b->right ) ) ; 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q) ;
    }
};


