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
    int             ans;
    map<long long,int>    val;

    void    traverse( TreeNode* root, long long target, long long sum )
    {
        if ( !root )
            return ;

        if ( val.find( sum + root->val - target ) != val.end() )
            ans += val[sum + root->val - target];

        cout << sum + root->val << endl;
        val[sum + root->val]++;
        
        if ( root->left )
            traverse( root->left, target, sum + root->val);

        if ( root->right )
            traverse( root->right, target, sum + root->val);
        
        val[sum + root->val]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if ( !root )
            return (0);
        
        ans = 0;
        val[0] = 1;
        traverse( root, targetSum, 0);
        
        return ( ans );
    }
};