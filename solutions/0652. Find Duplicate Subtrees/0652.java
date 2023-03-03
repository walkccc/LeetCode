class Solution {
  public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
    List<TreeNode> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();
    encode(root, count, ans);
    return ans;
  }

  private String encode(TreeNode root, Map<String, Integer> count, List<TreeNode> ans) {
    if (root == null)
      return "";

    final String encoded =
        root.val + "#" + encode(root.left, count, ans) + "#" + encode(root.right, count, ans);
    count.merge(encoded, 1, Integer::sum);
    if (count.get(encoded) == 2)
      ans.add(root);
    return encoded;
  }
}
