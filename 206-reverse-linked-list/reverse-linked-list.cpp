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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        
        if ( !head or !head->next )
            return ( head );
        
        ListNode *last_head = NULL;
        
        while ( head )
        {
            last_head = head;
            
            ListNode* next = head->next;
            
            head->next = temp;
            
            temp = head;
            head = next;
            
        }
        
        return ( last_head );
    }
};