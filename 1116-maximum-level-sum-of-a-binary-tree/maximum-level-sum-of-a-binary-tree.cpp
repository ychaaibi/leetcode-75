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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>  q;

        int ans = INT_MIN;
        int level = 0;
        int c_level = 0, sum = root->val;

        q.push( root );

        while ( !q.empty() )
        {

            c_level++;
            if ( sum > ans )
                ans = sum, level = c_level;
            sum = 0;
    
            int size = q.size();

            while ( size-- )
            {
                TreeNode* curr_node = q.front();

                q.pop();
                if ( curr_node->left )
                {
                    sum += curr_node->left->val;
                    q.push( curr_node->left );
                }
                
                if ( curr_node->right )
                {
                    sum += curr_node->right->val;
                    q.push( curr_node->right );
                }
            }
        }
        return ( level );
    }
};