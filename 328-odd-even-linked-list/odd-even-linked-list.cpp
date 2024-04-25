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
    ListNode* oddEvenList(ListNode* head) {
        if ( !head or !head->next )
            return ( head );
        
        ListNode *odd = head, *even_head = head->next, *even = head->next;
        
        while ( even and even->next )
        {
            odd->next = odd->next->next;
            even->next = odd->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = even_head;
        
        return ( head );
        
    }
};