class Solution {
  public TreeNode sortedListToBST(ListNode head) {
    List<Integer> A = new ArrayList<>();

    // Construct the array
    for (ListNode curr = head; curr != null; curr = curr.next)
      A.add(curr.val);

    return helper(A, 0, A.size() - 1);
  }

  private TreeNode helper(List<Integer> A, int l, int r) {
    if (l > r)
      return null;

    final int m = (l + r) / 2;
    TreeNode root = new TreeNode(A.get(m));
    root.left = helper(A, l, m - 1);
    root.right = helper(A, m + 1, r);
    return root;
  }
}
