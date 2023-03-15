class Solution {
  public int nextGreaterElement(int n) {
    final String s = nextPermutation(String.valueOf(n).toCharArray());
    final long ans = Long.parseLong(s);
    return ans > Integer.MAX_VALUE || ans <= (long) n ? -1 : (int) ans;
  }

  // Similar to 31. Next Permutation
  private String nextPermutation(char[] s) {
    final int n = s.length;

    int i;
    for (i = n - 2; i >= 0; --i)
      if (s[i] < s[i + 1])
        break;

    if (i >= 0) {
      for (int j = n - 1; j > i; --j)
        if (s[j] > s[i]) {
          swap(s, i, j);
          break;
        }
    }

    reverse(s, i + 1, n - 1);
    return new String(s);
  }

  private void reverse(char[] s, int l, int r) {
    while (l < r)
      swap(s, l++, r--);
  }

  private void swap(char[] s, int i, int j) {
    final char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
