class Solution {
  public boolean checkEqualTree(TreeNode root) {
    if (root == null)
      return false;

    Set<Integer> seen = new HashSet<>();
    final int sum = root.val + dfs(root.left, seen) + dfs(root.right, seen);
    return sum % 2 == 0 && seen.contains(sum / 2);
  }

  private int dfs(TreeNode root, Set<Integer> seen) {
    if (root == null)
      return 0;

    final int sum = root.val + dfs(root.left, seen) + dfs(root.right, seen);
    seen.add(sum);
    return sum;
  }
}
