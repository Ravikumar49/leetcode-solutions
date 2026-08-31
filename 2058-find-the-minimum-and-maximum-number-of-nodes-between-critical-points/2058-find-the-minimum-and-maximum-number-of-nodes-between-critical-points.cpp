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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};
        int minDistance = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currentIndex = 1;
        int prevCriticalIndex = 0;
        int firstCriticalIndex = 0;
        while(curr->next != nullptr) {
            if((prev->val < curr->val && curr->val > curr->next->val) || (prev->val > curr->val && curr->val < curr->next->val)) {
                if(prevCriticalIndex == 0) {
                    prevCriticalIndex = currentIndex;
                    firstCriticalIndex = currentIndex;
                }
                else {
                    minDistance = min(minDistance, currentIndex - prevCriticalIndex);
                    prevCriticalIndex = currentIndex;
                }
            }
            currentIndex++;
            prev = curr;
            curr = curr->next;
        }
        if(minDistance != INT_MAX) {
            int maxDistance = prevCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }
        return result;
    }
};