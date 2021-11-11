class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    auto compare = [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;  // min-heap
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

    for (ListNode* list : lists)
      if (list)
        pq.push(list);

    while (!pq.empty()) {
      ListNode* minNode = pq.top();
      pq.pop();
      if (minNode->next)
        pq.push(minNode->next);
      curr->next = minNode;
      curr = curr->next;
    }

    return dummy.next;
  }
};
