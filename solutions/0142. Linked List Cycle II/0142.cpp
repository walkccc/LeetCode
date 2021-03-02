class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }

    return nullptr;
  }
};
