class Solution {
  public boolean verifyPreorder(int[] preorder) {
    dfs(preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
    return i == preorder.length;
  }

  private int i = 0;

  private void dfs(int[] preorder, int mn, int mx) {
    if (i == preorder.length)
      return;
    if (preorder[i] < mn || preorder[i] > mx)
      return;

    final int val = preorder[i++];
    dfs(preorder, mn, val);
    dfs(preorder, val, mx);
  }
}
