class Solution {
  public int[] findMode(TreeNode root) {
    List<Integer> ans = new ArrayList<>();

    inorder(root, ans);

    return ans.stream().mapToInt(i -> i).toArray();
  }

  private TreeNode pred = null;
  private int count = 0;
  private int maxCount = 0;

  private void inorder(TreeNode root, List<Integer> ans) {
    if (root == null)
      return;

    inorder(root.left, ans);

    if (pred != null && pred.val == root.val)
      ++count;
    else
      count = 1;

    if (count > maxCount) {
      maxCount = count;
      ans.clear();
      ans.add(root.val);
    } else if (count == maxCount) {
      ans.add(root.val);
    }

    pred = root;
    inorder(root.right, ans);
  }
}
