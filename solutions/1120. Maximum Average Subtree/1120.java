class T {
  public int sum;
  public int count;
  public double maxAverage;
  public T(int sum, int count, double maxAverage) {
    this.sum = sum;
    this.count = count;
    this.maxAverage = maxAverage;
  }
}

class Solution {
  public double maximumAverageSubtree(TreeNode root) {
    return maximumAverage(root).maxAverage;
  }

  private T maximumAverage(TreeNode root) {
    if (root == null)
      return new T(0, 0, 0.0);

    T left = maximumAverage(root.left);
    T right = maximumAverage(root.right);

    final int sum = root.val + left.sum + right.sum;
    final int count = 1 + left.count + right.count;
    final double maxAverage =
        Math.max(sum / (double) count, Math.max(left.maxAverage, right.maxAverage));
    return new T(sum, count, maxAverage);
  }
}
