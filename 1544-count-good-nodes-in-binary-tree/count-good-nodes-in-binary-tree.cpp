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
    int ans;
    
    void    traverse(TreeNode* root, int val )
    {
        if ( !root )
            return ;
        
        if ( root->val >= val )
            ans++;
        traverse(root->left, max(val, root->val) );
        traverse(root->right, max(val, root->val) );
    }
    
    int goodNodes(TreeNode* root) {
        ans = 0;
        
        traverse( root, root->val );
        return ( ans );
    }
};