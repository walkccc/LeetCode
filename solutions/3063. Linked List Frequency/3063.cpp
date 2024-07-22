class Solution {
 public:
  ListNode* frequenciesOfElements(ListNode* head) {
    unordered_map<int, int> count;
    ListNode* curr = head;

    while (curr != nullptr) {
      ++count[curr->val];
      curr = curr->next;
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (const auto& [_, freq] : count) {
      tail->next = new ListNode(freq);
      tail = tail->next;
    }

    return dummy.next;
  }
};
