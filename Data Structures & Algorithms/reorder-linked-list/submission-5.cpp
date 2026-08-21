class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* second = slow -> next;
        slow -> next = nullptr;

        ListNode* prev = nullptr;
        while(second){
            ListNode* next = second -> next;
            second -> next = prev;
            prev = second;
            second = next;
        }

        ListNode* first = head;
        second = prev;
        while(second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
