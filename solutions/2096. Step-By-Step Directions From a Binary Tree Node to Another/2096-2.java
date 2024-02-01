class Solution {
  public String getDirections(TreeNode root, int startValue, int destValue) {
    StringBuilder pathToStart = new StringBuilder();
    StringBuilder pathToDest = new StringBuilder();

    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);

    while (pathToStart.length() > 0 && pathToDest.length() > 0 &&
           pathToStart.charAt(pathToStart.length() - 1) ==
               pathToDest.charAt(pathToDest.length() - 1)) {
      pathToStart.setLength(pathToStart.length() - 1);
      pathToDest.setLength(pathToDest.length() - 1);
    }

    return "U".repeat(pathToStart.length()) + pathToDest.reverse().toString();
  }

  // Builds the string in the reverse order to avoid creating a new copy.
  private boolean dfs(TreeNode root, int val, StringBuilder sb) {
    if (root.val == val)
      return true;
    if (root.left != null && dfs(root.left, val, sb))
      sb.append("L");
    else if (root.right != null && dfs(root.right, val, sb))
      sb.append("R");
    return sb.length() > 0;
  }
}
