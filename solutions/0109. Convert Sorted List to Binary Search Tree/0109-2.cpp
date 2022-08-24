class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    vector<int> A;

    // construct the array
    for (ListNode* curr = head; curr; curr = curr->next)
      A.push_back(curr->val);

    return helper(A, 0, A.size() - 1);
  }

 private:
  TreeNode* helper(const vector<int>& A, int l, int r) {
    if (l > r)
      return nullptr;

    const int m = (l + r) / 2;
    TreeNode* root = new TreeNode(A[m]);
    root->left = helper(A, l, m - 1);
    root->right = helper(A, m + 1, r);
    return root;
  }
};
