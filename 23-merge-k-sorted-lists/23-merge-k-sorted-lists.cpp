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
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        priority_queue<pair<int, ListNode*>> pq;
        
        for (auto L : lists)
            if (L) pq.emplace(-L->val, L);
        
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            ans->next = node;
            ans = ans->next;
            if (node->next) {
                node = node->next;
                pq.emplace(-node->val, node);
            }
        }
        return cur->next;
    }
};