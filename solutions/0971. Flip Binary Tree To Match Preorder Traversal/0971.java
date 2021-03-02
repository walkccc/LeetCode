class Solution {
  public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
    List<Integer> ans = new ArrayList<>();

    dfs(root, voyage, ans);

    return ans;
  }

  private int i = 0;

  private void dfs(TreeNode root, int[] voyage, List<Integer> ans) {
    if (root == null)
      return;
    if (root.val != voyage[i++]) {
      ans.clear();
      ans.add(-1);
      return;
    }

    if (i < voyage.length && root.left != null && root.left.val != voyage[i]) {
      // flip root
      ans.add(root.val);
      dfs(root.right, voyage, ans);
      dfs(root.left, voyage, ans);
    } else {
      dfs(root.left, voyage, ans);
      dfs(root.right, voyage, ans);
    }
  }
}
