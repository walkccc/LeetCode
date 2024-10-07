class Solution {
  public boolean isSubPath(ListNode head, TreeNode root) {
    if (root == null)
      return false;
    return isContinuousSubPath(head, root) || isSubPath(head, root.left) ||
        isSubPath(head, root.right);
  }

  private boolean isContinuousSubPath(ListNode head, TreeNode root) {
    if (head == null)
      return true;
    if (root == null)
      return false;
    return head.val == root.val &&
        (isContinuousSubPath(head.next, root.left) || isContinuousSubPath(head.next, root.right));
  }
}
