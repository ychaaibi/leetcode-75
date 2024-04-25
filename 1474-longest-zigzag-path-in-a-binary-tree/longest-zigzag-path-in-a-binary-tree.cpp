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
    int ans = 0;
    
    void traverse( TreeNode* root, int type, int curr )
    {   
        if ( !root )
            return ;
        
        ans = max( ans, curr - 1 );
        
        if ( type == 0 )
        {
            traverse( root->left, 1, curr + 1);
            traverse( root->right, 2, curr + 1);
        }
        else if ( type == 1 )
        {
            traverse( root->left, 1, 2);
            traverse( root->right, 2, curr + 1);
        }
        else
        {
            traverse( root->right, 2, 2);
            traverse( root->left, 1, curr + 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        ans = 0;
        traverse( root, 0, 1 );
        
        return ( ans );
    }
};