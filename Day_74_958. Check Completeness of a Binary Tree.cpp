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
    bool bfs( TreeNode * src ){
        queue<TreeNode*> q;
        queue<TreeNode*> spare ; 
        q.push(src);
        while(!q.empty()){
            int sz = q.size();
            bool lst = 1 ;
            while(sz--){
                auto curr = q.front();
                spare.push(curr);
                q.pop();
                if ( curr == NULL ) {
                    continue ;
                }                
                lst &= ( curr->left  == NULL  ) ;
                lst &= ( curr->right == NULL  ) ;
                
                q.push(curr->left);
                q.push(curr->right);
                
            }
            if(lst){
                bool nil = 0 ;
                while(!spare.empty()){
                    auto curr = spare.front();
                    spare.pop();
                    if( curr == NULL ) nil = true ;
                    if( curr != NULL && nil ) return false; 
                }
            }
        }   
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return bfs(root);
    }
};
