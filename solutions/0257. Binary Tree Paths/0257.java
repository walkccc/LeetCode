class Solution {
  public List<String> binaryTreePaths(TreeNode root) {
    List<String> ans = new ArrayList<>();

    dfs(root, new StringBuilder(), ans);

    return ans;
  }

  private void dfs(TreeNode root, StringBuilder path, List<String> ans) {
    if (root == null)
      return;
    if (root.left == null && root.right == null) {
      ans.add(path.append(root.val).toString());
      return;
    }

    final int length = path.length();
    dfs(root.left, path.append(root.val).append("->"), ans);
    path.setLength(length);
    dfs(root.right, path.append(root.val).append("->"), ans);
    path.setLength(length);
  }
}