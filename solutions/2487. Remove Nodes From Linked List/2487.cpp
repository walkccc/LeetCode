class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    head->next = removeNodes(head->next);
    return head->next != nullptr && head->val < head->next->val ? head->next
                                                                : head;
  }
};
