class T {
  public int min;  // min value in the subtree
  public int max;  // max value in the subtree
  public int size; // total size of the subtree

  public T(int min, int max, int size) {
    this.min = min;
    this.max = max;
    this.size = size;
  }
}

class Solution {
  public int largestBSTSubtree(TreeNode root) {
    return dfs(root).size;
  }

  private T dfs(TreeNode root) {
    if (root == null)
      return new T(Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

    T l = dfs(root.left);
    T r = dfs(root.right);

    if (l.max < root.val && root.val < r.min)
      return new T(Math.min(l.min, root.val), Math.max(r.max, root.val), 1 + l.size + r.size);

    // mark as invalid one, but still record the size of children
    // return (-INF, INF) because any node won't > INT and < -INF
    return new T(Integer.MIN_VALUE, Integer.MAX_VALUE, Math.max(l.size, r.size));
  }
}
