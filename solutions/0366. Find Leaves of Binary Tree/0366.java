class Solution {
  public List<List<Integer>> findLeaves(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();

    height(root, ans);

    return ans;
  }

  // height of root
  private int height(TreeNode root, List<List<Integer>> ans) {
    if (root == null)
      return 0;

    final int h = 1 + Math.max(height(root.left, ans), height(root.right, ans));
    if (ans.size() == h - 1) // meet leaf
      ans.add(new ArrayList<>());
    ans.get(h - 1).add(root.val);

    return h;
  }
}