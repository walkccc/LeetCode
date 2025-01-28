class Solution {
 public:
  string gameResult(ListNode* head) {
    int even = 0;
    int odd = 0;

    while (head != nullptr) {
      if (head->val > head->next->val)
        ++even;
      else if (head->val < head->next->val)
        ++odd;
      head = head->next->next;
    }

    if (even > odd)
      return "Even";
    if (even < odd)
      return "Odd";
    return "Tie";
  }
};
