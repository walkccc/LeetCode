class Solution {
  public int maxProduct(TreeNode root) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    List<Integer> allSums = new ArrayList<>();
    final long totalSum = treeSum(root, allSums);

    for (final long sum : allSums)
      ans = Math.max(ans, sum * (totalSum - sum));

    return (int) (ans % kMod);
  }

  private int treeSum(TreeNode root, List<Integer> allSums) {
    if (root == null)
      return 0;

    final int leftSum = treeSum(root.left, allSums);
    final int rightSum = treeSum(root.right, allSums);
    final int sum = root.val + leftSum + rightSum;
    allSums.add(sum);
    return sum;
  }
}
