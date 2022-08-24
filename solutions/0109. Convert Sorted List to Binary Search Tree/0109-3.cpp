class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    this->head = head;
    return helper(0, getLength(head) - 1);
  }

 private:
  ListNode* head;

  TreeNode* helper(int l, int r) {
    if (l > r)
      return nullptr;

    const int m = (l + r) / 2;

    // simulate inorder traversal: recursively form the left half
    TreeNode* left = helper(l, m - 1);

    // once left half is traversed, process the current node
    TreeNode* root = new TreeNode(head->val);
    root->left = left;

    // maintain the invariance
    head = head->next;

    // simulate inorder traversal: recursively form the right half
    root->right = helper(m + 1, r);
    return root;
  }

  int getLength(ListNode* head) {
    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next)
      ++length;
    return length;
  }
};
