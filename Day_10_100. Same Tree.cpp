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




// ########################################################################################
// solution 2 : using normal traversal as ( preorder ) but keep track of nulls you meet 
// ########################################################################################


// why keep track of nulls ? 
// as diffrent structure trees may have same preorder traversal [ no gurantee on unique structure ]

// study examples :: 

// [1,2,3]
// [1,2,null,3]
// diffrent trees but has the same non-null pre order of 1,2,3

// [1,2,3]
// [3,1,null,2]
// diffrent trees but has the same non-null in order of 2,1,3


// [1,2,3]
// [1,3,null,2]
// diffrent trees but has the same non-null post order of 2,3,1


// test using preorder 
class Solution {
public:
    const int inf = 0x3f3f3f3f ; // for null reprsentation 
    


    void dfs( TreeNode* node , vector<int> & ans ) {
        if ( node == NULL ) {
            ans.push_back(inf); // keep track of nulls
            return ; 
        }
        ans.push_back(node->val);
        dfs( node->left  , ans ) ;
        dfs( node->right , ans ) ; 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a , b ; 
        dfs(p,a) , dfs(q,b);
        return (a == b) ;  
    }
}


