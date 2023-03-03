class Solution {
  public List<String> binaryTreePaths(TreeNode root) {
    List<String> ans = new ArrayList<>();
    dfs(root, new StringBuilder(), ans);
    return ans;
  }

  private void dfs(TreeNode root, StringBuilder sb, List<String> ans) {
    if (root == null)
      return;
    if (root.left == null && root.right == null) {
      ans.add(sb.append(root.val).toString());
      return;
    }

    final int length = sb.length();
    dfs(root.left, sb.append(root.val).append("->"), ans);
    sb.setLength(length);
    dfs(root.right, sb.append(root.val).append("->"), ans);
    sb.setLength(length);
  }
}
