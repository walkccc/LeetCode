class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return new TreeNode(head->val);

    ListNode* mid = findMid(head);
    TreeNode* root = new TreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
  }

 private:
  ListNode* findMid(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;

    return slow;
  }
};
