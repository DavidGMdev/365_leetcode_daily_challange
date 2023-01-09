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

// #########################################################################################################
// Solution 1 : recursive dfs ( Depth first search ) [ using recursion ][ recursive function calls ]
// #########################################################################################################

class Solution {
public:
    // pre = (V)LR
    void dfs( TreeNode* node , vector<int>& ans ) {
        if ( node == NULL ) return; 
        ans.push_back(node->val) ; 
        dfs(node->left,ans);
        dfs(node->right,ans);
    }   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans ; 
        dfs(root,ans);
        return ans;
    }
};

// #########################################################################################################
// Solution 2 : iterative dfs ( Depth first search ) [ using stack ]
// #########################################################################################################

class Solution {
public:
    // pre = (V)LR 
    vector<int> preorderTraversal(TreeNode* root) {
        // try iterative using stack 
        vector<int> ans ; 
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty() && stk.top() != NULL ){
            // fetch the current node 
            TreeNode* top = stk.top();
            stk.pop();
            
            // push right first ( to be done latest )  
            if ( top->right != NULL ) stk.push( top->right ); 
            
            if ( top->left  != NULL ) stk.push( top->left  );
            
            // get the top itself ( it's preorder one )
            ans.push_back( top->val );
          
            // inverted as it's using stack
            // check for nulls to avoid useless push/pop time and useless space of nulls in stack 
            // and that's it <3
        }
        return ans;
    }
};



