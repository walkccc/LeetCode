class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
      a = a == nullptr ? headB : a->next;
      b = b == nullptr ? headA : b->next;
    }

    return a;
  }
};
