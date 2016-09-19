// pay attention to add another node
// check if last node
// https://leetcode.com/problems/plus-one-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // the carry on of the next node
    int visit(ListNode* head) {
        if (!head->next) {
            // if it's the last node
            head->val += 1;
            int rcarry = head->val / 10;
            head->val %= 10;
            return rcarry;
        }
        head->val += visit(head->next);
        int rcarry = head->val / 10;
        head->val %= 10;
        return rcarry;
    }

    ListNode* plusOne(ListNode* head) {
        if (head) {
            int carry = visit(head);
            if (carry) {
                ListNode* newhead = new ListNode(1);
                newhead->next = head;
                return newhead;
            }
        }
        return head;
    }
};