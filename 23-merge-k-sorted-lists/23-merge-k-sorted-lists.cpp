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
        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;
        int n = lists.size();
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
                
        for (int i = 0; i < n; i++)
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        
        while (!pq.empty()) {
            auto [x, head] = pq.top();
            pq.pop();
            res->next = new ListNode(x);
            res = res->next;
            head = head->next;
            if (head)
                pq.push({head->val, head});
        }
        return ans->next;
    }
};