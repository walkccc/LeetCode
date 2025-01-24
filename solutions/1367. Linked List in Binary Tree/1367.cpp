class Solution {
 public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (root == nullptr)
      return false;
    return isContinuousSubPath(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }

 private:
  bool isContinuousSubPath(ListNode* head, TreeNode* root) {
    if (head == nullptr)
      return true;
    if (root == nullptr)
      return false;
    return head->val == root->val &&
           (isContinuousSubPath(head->next, root->left) ||
            isContinuousSubPath(head->next, root->right));
  }
};
