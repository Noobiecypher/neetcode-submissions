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
        ListNode* pehla = head;
        while(n--){
            pehla = pehla -> next;
        } 
        while(pehla){
            pehla = pehla -> next;
            tail = tail -> next;
        }

        tail -> next = tail -> next -> next;
        return dummy.next;
    }
};
