class Solution {
  public int[] findMode(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    // count[0] := currCount
    // count[1] := maxCount
    int[] count = new int[2];

    inorder(root, count, ans);
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private TreeNode pred = null;

  private void inorder(TreeNode root, int[] count, List<Integer> ans) {
    if (root == null)
      return;

    inorder(root.left, count, ans);
    updateCount(root, count, ans);
    inorder(root.right, count, ans);
  }

  private void updateCount(TreeNode root, int[] count, List<Integer> ans) {
    if (pred != null && pred.val == root.val)
      ++count[0];
    else
      count[0] = 1;

    if (count[0] > count[1]) {
      count[1] = count[0];
      ans.clear();
      ans.add(root.val);
    } else if (count[0] == count[1]) {
      ans.add(root.val);
    }

    pred = root;
  }
}
