class Solution {
public:
    unordered_map<string,int>mp;
    unordered_map<string,TreeNode*>mp2;
    string dfs( TreeNode* node ){
        string segment = "";
        if( node == NULL ) {
            segment += "#" ;
            return segment ;
        }
        segment += to_string(node->val)+","+dfs(node->left)+","+dfs(node->right);
        // cout << segment << endl;
        mp[segment]++;
        mp2[segment] = node;
        return segment ;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> ans; 
        for( auto i : mp ){
            if( i.second > 1 ) ans.push_back( mp2[i.first] );
        }
        return ans;
    }
};
