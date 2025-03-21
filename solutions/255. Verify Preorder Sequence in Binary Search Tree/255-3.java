class Solution {
  public boolean verifyPreorder(int[] preorder) {
    int low = Integer.MIN_VALUE;
    int i = -1;

    for (final int p : preorder) {
      if (p < low)
        return false;
      while (i >= 0 && preorder[i] < p)
        low = preorder[i--];
      preorder[++i] = p;
    }

    return true;
  }
}
