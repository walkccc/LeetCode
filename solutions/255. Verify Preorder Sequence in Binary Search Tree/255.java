class Solution {
  public boolean verifyPreorder(int[] preorder) {
    dfs(preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
    return i == preorder.length;
  }

  private int i = 0;

  private void dfs(int[] preorder, int min, int max) {
    if (i == preorder.length)
      return;
    if (preorder[i] < min || preorder[i] > max)
      return;

    final int val = preorder[i++];
    dfs(preorder, min, val);
    dfs(preorder, val, max);
  }
}
