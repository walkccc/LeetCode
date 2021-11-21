class Solution {
  public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
    List<TreeNode> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    preorder(root, count, ans);

    return ans;
  }

  private StringBuilder preorder(TreeNode root, Map<String, Integer> count, List<TreeNode> ans) {
    if (root == null)
      return new StringBuilder("#");

    StringBuilder sb = new StringBuilder(String.valueOf(root.val))
                           .append(",")
                           .append(preorder(root.left, count, ans))
                           .append(",")
                           .append(preorder(root.right, count, ans));
    final String hashed = sb.toString();

    if (count.containsKey(hashed) && count.get(hashed) == 1)
      ans.add(root);
    count.put(hashed, count.getOrDefault(hashed, 0) + 1);

    return sb;
  }
}
