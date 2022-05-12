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

    T l = maximumAverage(root.left);
    T r = maximumAverage(root.right);

    final int sum = root.val + l.sum + r.sum;
    final int count = 1 + l.count + r.count;
    final double maxAverage = Math.max(sum / (double) count, Math.max(l.maxAverage, r.maxAverage));
    return new T(sum, count, maxAverage);
  }
}
