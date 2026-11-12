class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>,
        function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

       
        for (auto node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = curr->next;

            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        curr->next = nullptr;

        return dummy->next;
    }
};
