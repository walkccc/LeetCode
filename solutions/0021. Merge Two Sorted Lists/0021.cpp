class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2)
      return l1 ? l1 : l2;

    if (l1->val > l2->val)
      swap(l1, l2);
    l1->next = mergeTwoLists(l1->next, l2);

    return l1;
  }
};
