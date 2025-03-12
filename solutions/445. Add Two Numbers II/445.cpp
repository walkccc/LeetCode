class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;

    while (l1) {
      stack1.push(l1);
      l1 = l1->next;
    }

    while (l2) {
      stack2.push(l2);
      l2 = l2->next;
    }

    ListNode* head = nullptr;
    int carry = 0;

    while (carry || !stack1.empty() || !stack2.empty()) {
      if (!stack1.empty())
        carry += stack1.top()->val, stack1.pop();
      if (!stack2.empty())
        carry += stack2.top()->val, stack2.pop();
      ListNode* node = new ListNode(carry % 10);
      node->next = head;
      head = node;
      carry /= 10;
    }

    return head;
  }
};
