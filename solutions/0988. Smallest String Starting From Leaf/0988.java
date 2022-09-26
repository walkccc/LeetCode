class Solution {
  public String smallestFromLeaf(TreeNode root) {
    dfs(root, new StringBuilder());
    return ans;
  }

  private String ans = null;

  private void dfs(TreeNode root, StringBuilder sb) {
    if (root == null)
      return;

    sb.append((char) (root.val + 'a'));

    if (root.left == null && root.right == null) {
      final String path = sb.reverse().toString();
      sb.reverse(); // roll back
      if (ans == null || ans.compareTo(path) > 0)
        ans = path;
    }

    dfs(root.left, sb);
    dfs(root.right, sb);
    sb.deleteCharAt(sb.length() - 1);
  }
}
