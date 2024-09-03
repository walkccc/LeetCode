class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head->next;

    while (curr != nullptr) {
      ListNode* running = curr;
      int sum = 0;
      while (running->val > 0) {
        sum += running->val;
        running = running->next;
      }
      curr->val = sum;
      curr->next = running->next;
      curr = running->next;
    }

    return head->next;
  }
};
