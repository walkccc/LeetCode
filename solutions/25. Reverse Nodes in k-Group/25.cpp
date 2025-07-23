class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr)
      return nullptr;

    ListNode* tail = head;

    for (int i = 0; i < k; ++i) {
      // There are less than k nodes in the list, do nothing.
      if (tail == nullptr)
        return head;
      tail = tail->next;
    }

    ListNode* newHead = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
  }

 private:
  // Reverses [head, tail).
  ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != tail) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
