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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        tail -> next = head;
        ListNode* right = head;
        while(n--){
            right = right -> next;
        }

        while(right){
            right = right -> next;
            tail = tail -> next;
        }

        tail -> next = tail -> next -> next;
        return dummy.next;
    }
};
