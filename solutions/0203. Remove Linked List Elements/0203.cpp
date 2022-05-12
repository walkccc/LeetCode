class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    for (; head; head = head->next)
      if (head->val != val) {
        prev->next = head;
        prev = prev->next;
      }
    prev->next = nullptr;  // in case the last val == val

    return dummy.next;
  }
};
