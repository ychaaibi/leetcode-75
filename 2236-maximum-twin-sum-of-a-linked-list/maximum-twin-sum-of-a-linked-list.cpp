/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* hare = head, *turtle = head;
        
        while ( hare and hare->next )
        {
            hare = hare->next->next;
            turtle = turtle->next;
        }
        
        ListNode* prev_node = turtle, *next, *mid = turtle;
        
        turtle = turtle->next;
        
        while ( turtle )
        {
            next = turtle->next;

            turtle->next = prev_node;
    
            prev_node = turtle;
            turtle = next;
        }
        
        ListNode* left = head, *right = prev_node;
        
        int ans = 0;
        
        while ( left != mid )
        {
            ans = max(left->val + right->val, ans);
            left = left->next;
            right = right->next;
        }
        return (ans);
        
    }
};