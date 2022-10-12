class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    if (!head)
      return new ListNode(1);
    if (addOne(head) == 1)
      return new ListNode(1, head);
    return head;
  }

 private:
  int addOne(ListNode* node) {
    const int carry = node->next ? addOne(node->next) : 1;
    const int sum = node->val + carry;
    node->val = sum % 10;
    return sum / 10;
  }
};
