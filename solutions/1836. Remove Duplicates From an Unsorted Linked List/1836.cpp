class Solution {
 public:
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    ListNode dummy(0, head);
    unordered_map<int, int> count;

    for (ListNode* curr = head; curr; curr = curr->next)
      ++count[curr->val];

    ListNode* curr = &dummy;

    while (curr != nullptr) {
      while (curr->next && count.contains(curr->next->val) &&
             count[curr->next->val] > 1)
        curr->next = curr->next->next;
      curr = curr->next;
    }

    return dummy.next;
  }
};
