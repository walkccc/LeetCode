class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head->next;

    while (curr) {
      ListNode* running = curr;
      int sum = 0;
      while (running->val) {
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
