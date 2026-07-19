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
    ListNode* reverse(ListNode* p) {
        ListNode* prev = NULL;
        ListNode* curr = p;
        ListNode* next = NULL;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = NULL;
        ListNode* fast = NULL;
        slow = head;
        fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* headSecondHalf = NULL;
        headSecondHalf = reverse(slow);
        ListNode* start = NULL;
        start = head;
        while(start->next && headSecondHalf->next) {
            ListNode* temp = start->next;
            start->next = headSecondHalf;
            start = temp;

            temp = headSecondHalf->next;
            headSecondHalf->next = start;
            headSecondHalf = temp;
        }
    }
};