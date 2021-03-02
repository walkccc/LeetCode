class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }

    return a;
  }
};
