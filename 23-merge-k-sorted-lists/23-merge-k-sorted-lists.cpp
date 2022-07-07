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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
        int n = lists.size();
        
        for (int i = 0; i < n; i++)
            if (lists[i])
                pq.push({-lists[i]->val, lists[i]});
        
        while (!pq.empty()) {
            auto [x, head] = pq.top();
            pq.pop();
            cur->next = new ListNode(-x);
            cur = cur->next;
            head = head->next;
            if (head)
                pq.push({-head->val, head});
        }
        return res->next;
    }
};