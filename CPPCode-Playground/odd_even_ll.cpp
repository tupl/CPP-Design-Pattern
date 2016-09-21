// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // if empty node
        if (!head) return head;
        
        ListNode* even = head, *prev_even = nullptr;
        ListNode* odd = head->next;
        ListNode* odd_begin = head->next;
        while(even && odd) {
            prev_even = even;
            even->next = odd->next;
            even = even->next;
            if (even) {
                odd->next = even->next;
                odd = odd->next;
            }
        }
        
        if (!odd) {
            // odd element
            prev_even = even;
        }
        
        if (prev_even) {
            prev_even->next = odd_begin;
        }
        return head;
    }
};