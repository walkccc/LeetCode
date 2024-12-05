class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    if (!head->next->val) {
      ListNode* node = new ListNode(head->val);
      node->next = mergeNodes(head->next->next);
      return node;
    }

    ListNode* next = mergeNodes(head->next);
    next->val += head->val;
    return next;
  }
};
