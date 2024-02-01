class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Delete the middle node.
    slow->next = slow->next->next;
    return dummy.next;
  }
};
