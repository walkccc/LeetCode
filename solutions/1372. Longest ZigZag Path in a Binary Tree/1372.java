class T {
  public int leftMax;
  public int rightMax;
  public int subtreeMax;

  public T(int leftMax, int rightMax, int subtreeMax) {
    this.leftMax = leftMax;
    this.rightMax = rightMax;
    this.subtreeMax = subtreeMax;
  }
}

class Solution {
  public int longestZigZag(TreeNode root) {
    return dfs(root).subtreeMax;
  }

  private T dfs(TreeNode root) {
    if (root == null)
      return new T(-1, -1, -1);
    T left = dfs(root.left);
    T right = dfs(root.right);
    final int leftZigZag = left.rightMax + 1;
    final int rightZigZag = right.leftMax + 1;
    final int subtreeMax =
        Math.max(Math.max(leftZigZag, rightZigZag), Math.max(left.subtreeMax, right.subtreeMax));
    return new T(leftZigZag, rightZigZag, subtreeMax);
  }
}
