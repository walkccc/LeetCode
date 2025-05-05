class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(
        compare);

    for (ListNode* list : lists)
      if (list != nullptr)
        minHeap.push(list);

    while (!minHeap.empty()) {
      ListNode* minNode = minHeap.top();
      minHeap.pop();
      if (minNode->next)
        minHeap.push(minNode->next);
      curr->next = minNode;
      curr = curr->next;
    }

    return dummy.next;
  }
};
