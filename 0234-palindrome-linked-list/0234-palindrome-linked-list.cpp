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
    ListNode* reverse(ListNode* p1) {
        ListNode* prev = NULL;
        ListNode* curr = p1;
        ListNode* next = NULL;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = NULL;
        ListNode* fast = NULL;
        fast = head;
        slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = reverse(slow);
        ListNode* p1 = head;
        while(p1!=NULL && p!=NULL) {
            if(p1->val != p->val) return false;
            p1 = p1->next;
            p = p->next;
        }
        return true;
    }
};