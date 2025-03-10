class Solution {
  public TreeNode sortedListToBST(ListNode head) {
    List<Integer> arr = new ArrayList<>();

    // Construct the array.
    for (ListNode curr = head; curr != null; curr = curr.next)
      arr.add(curr.val);

    return helper(arr, 0, arr.size() - 1);
  }

  private TreeNode helper(List<Integer> arr, int l, int r) {
    if (l > r)
      return null;
    final int m = (l + r) / 2;
    TreeNode root = new TreeNode(arr.get(m));
    root.left = helper(arr, l, m - 1);
    root.right = helper(arr, m + 1, r);
    return root;
  }
}
