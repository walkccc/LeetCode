class Solution {
  public List<Integer> boundaryOfBinaryTree(TreeNode root) {
    if (root == null)
      return new ArrayList<>();
    List<Integer> ans = new ArrayList<>(Arrays.asList(root.val));
    dfs(root.left, true, false, ans);
    dfs(root.right, false, true, ans);
    return ans;
  }

  // 1. root.left is left boundary if root is left boundary.
  //    root.right if left boundary if root.left == nullptr.
  // 2. Same applys for right boundary.
  // 3. If root is left boundary, add it before 2 children - preorder.
  //    If root is right boundary, add it after 2 children - postorder.
  // 4. A leaf that is neighter left/right boundary belongs to the bottom.
  private void dfs(TreeNode root, boolean lb, boolean rb, List<Integer> ans) {
    if (root == null)
      return;
    if (lb)
      ans.add(root.val);
    if (!lb && !rb && root.left == null && root.right == null)
      ans.add(root.val);

    dfs(root.left, lb, rb && root.right == null, ans);
    dfs(root.right, lb && root.left == null, rb, ans);
    if (rb)
      ans.add(root.val);
  }
}
