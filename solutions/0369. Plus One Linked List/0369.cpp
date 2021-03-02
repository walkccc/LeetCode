class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* i = dummy;
    dummy->next = head;

    while (head) {
      if (head->val != 9)
        i = head;
      head = head->next;
    }
    // i point to the rightmost non-9 node

    ++i->val;
    while (i->next) {
      i->next->val = 0;
      i = i->next;
    }

    return dummy->val == 0 ? dummy->next : dummy;
  }
};
