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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* hare = head, *turtle = head;
        
        if ( !head->next )
            return ( NULL );
        
        while ( hare->next and hare->next->next and hare->next->next->next )
        {
            hare = hare->next->next;
            turtle = turtle->next;
        }
        
        turtle->next = turtle->next->next;
        return ( head );
    }
};

// 