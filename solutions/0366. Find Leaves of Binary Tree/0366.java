class Solution {
  public List<List<Integer>> findLeaves(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();

    depth(root, ans);
    return ans;
  }

  // Returns the depth of the root (0-indexed).
  private int depth(TreeNode root, List<List<Integer>> ans) {
    if (root == null)
      return -1;

    final int l = depth(root.left, ans);
    final int r = depth(root.right, ans);
    final int h = 1 + Math.max(l, r);
    if (ans.size() == h) // Meet a leaf.
      ans.add(new ArrayList<>());

    ans.get(h).add(root.val);
    return h;
  }
}
