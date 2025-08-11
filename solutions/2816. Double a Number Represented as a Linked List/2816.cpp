class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    if (getCarry(head) == 1)
      return new ListNode(1, head);
    return head;
  }

 private:
  int getCarry(ListNode* node) {
    int val = node->val * 2;
    if (node->next != nullptr)
      val += getCarry(node->next);

    node->val = val % 10;
    return val / 10;
  }
};
