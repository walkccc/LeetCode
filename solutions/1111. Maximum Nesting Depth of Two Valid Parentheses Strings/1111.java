class Solution {
  public int[] maxDepthAfterSplit(String seq) {
    int[] ans = new int[seq.length()];
    int depth = 1;

    // Put all odd-depth parentheses in one group and even-depth parentheses in the other group.
    for (int i = 0; i < seq.length(); ++i)
      if (seq.charAt(i) == '(')
        ans[i] = ++depth % 2;
      else
        ans[i] = depth-- % 2;

    return ans;
  }
}
