class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(0);
    ListNode* prev = &dummy;  // the last (largest) of the sorted list

    while (head) {                  // current inserting node
      ListNode* next = head->next;  // cache next inserting node
      if (prev->val >= head->val)   // `prev` >= current inserting node
        prev = &dummy;              // move `prev` to the front
      while (prev->next && prev->next->val < head->val)
        prev = prev->next;
      head->next = prev->next;
      prev->next = head;
      head = next;  // update current inserting node
    }

    return dummy.next;
  }
};
