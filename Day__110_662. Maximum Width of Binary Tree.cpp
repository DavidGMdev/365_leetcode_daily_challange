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

typedef unsigned long long ll ;
class Solution {
public:
    int mx = 0 ;
    void bfs( TreeNode* src ){
        queue<pair<TreeNode*,int>>q;
        q.push({src,1});
        int level = 1 ;
        while(!q.empty()){
            int len = q.size();
            int l = INT_MAX, r = INT_MIN ;
            int base = q.front().second ; // base of this level 
            for( int i = 0 ; i < len ; i++ ){
                auto curr = q.front();
                q.pop();

                l = min(l,curr.second);
                r = max(r,curr.second);

                int idx = curr.second - base ;
                if( curr.first->left != NULL )
                    q.push({curr.first->left,2LL*idx+1});

                if( curr.first->right != NULL )
                    q.push({curr.first->right,2LL*idx+2});
            }
            if ( l == INT_MAX ) continue;
            mx = max(mx,r-l+1);
        }
        
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        bfs(root);
        return mx;
    }
};
