class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    dummy->next = head;

    while (head != nullptr) {
      if (head->val != 9)
        curr = head;
      head = head->next;
    }
    // `curr` now points to the rightmost non-9 node.

    ++curr->val;
    while (curr->next) {
      curr->next->val = 0;
      curr = curr->next;
    }

    return dummy->val == 0 ? dummy->next : dummy;
  }
};
