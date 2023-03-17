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
    unordered_map<int,int> idx ;
    int pstIdx ;
    TreeNode* build(int l , int r , vector<int>& in , vector<int>& post){

        if( l > r ) return NULL;

        TreeNode* node = new TreeNode( post[pstIdx] );

        int inIdx = idx[ post[pstIdx] ] ;
        pstIdx--;

        node->right = build(inIdx+1,r,in,post);
        node->left  = build(l,inIdx-1,in,post); 

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        // in order   = LVR
        // post order = LRV
        for ( int i = 0 ; i < inorder.size() ; i++ ) idx[ inorder[i] ] = i ;
        pstIdx = inorder.size() - 1 ; // root of tree 
        return build(0,inorder.size()-1,inorder,postorder);
    }
};
