class Solution {
 public:
  ListNode* sortLinkedList(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr != nullptr)
      if (curr->val < 0) {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }

    return head;
  }
};
