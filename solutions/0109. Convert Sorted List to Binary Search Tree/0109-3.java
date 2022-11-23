class Solution {
  public TreeNode sortedListToBST(ListNode head) {
    this.head = head;
    return helper(0, getLength(head) - 1);
  }

  private ListNode head;

  private TreeNode helper(int l, int r) {
    if (l > r)
      return null;

    final int m = (l + r) / 2;

    // Simulate inorder traversal: recursively form the left half
    TreeNode left = helper(l, m - 1);

    // Once left half is traversed, process the current node
    TreeNode root = new TreeNode(head.val);
    root.left = left;

    // Maintain the invariance
    head = head.next;

    // Simulate inorder traversal: recursively form the right half
    root.right = helper(m + 1, r);

    return root;
  }

  private int getLength(ListNode head) {
    int length = 0;
    for (ListNode curr = head; curr != null; curr = curr.next)
      ++length;
    return length;
  }
}
