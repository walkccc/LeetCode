class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    vector<int> arr;

    // Construct the array.
    for (ListNode* curr = head; curr; curr = curr->next)
      arr.push_back(curr->val);

    return helper(arr, 0, arr.size() - 1);
  }

 private:
  TreeNode* helper(const vector<int>& arr, int l, int r) {
    if (l > r)
      return nullptr;
    const int m = (l + r) / 2;
    TreeNode* root = new TreeNode(arr[m]);
    root->left = helper(arr, l, m - 1);
    root->right = helper(arr, m + 1, r);
    return root;
  }
};
