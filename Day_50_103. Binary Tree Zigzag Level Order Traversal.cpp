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
    vector<vector<int>> ZigZagBfs( TreeNode* src ){
        queue<TreeNode*> q ;
        bool flg = 0 ; 
        q.push(src);
        vector<vector<int>> ans; 
        while (!q.empty()){
            int level_size = q.size();
            vector<int> level; 
            while (level_size--){
                TreeNode* curr = q.front();
                q.pop();
                if ( curr == NULL ) continue ;
                else level z.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if(flg) reverse(level.begin(),level.end());
            if(!level.empty()) ans.push_back(level);
            flg^=1 ; 
            
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return ZigZagBfs(root);
    }
};
