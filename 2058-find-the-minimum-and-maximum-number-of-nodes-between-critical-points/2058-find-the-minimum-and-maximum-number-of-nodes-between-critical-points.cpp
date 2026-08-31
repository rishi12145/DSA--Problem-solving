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
        
        int pos = 1;
        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;

        ListNode* curr = head->next;

        while (curr->next != NULL) {
            
            int before = curr->val; // current
            int left = curr->val;   // just for understanding

            // Check critical point
            if ((curr->val > curr->next->val && curr->val > head->val) ||
                (curr->val < curr->next->val && curr->val < head->val)) {
                
                if (first == -1) {
                    first = pos;
                } 
                else {
                    minDist = min(minDist, pos - prev);
                }

                prev = pos;
            }

            head = curr;
            curr = curr->next;
            pos++;
        }

        if (first == -1 || first == prev)
            return {-1, -1};

        return {minDist, prev - first};
    }
};