class Solution {
  public int[] findPermutation(String s) {
    int[] ans = new int[s.length() + 1];

    for (int i = 0; i < ans.length; ++i)
      ans[i] = i + 1;

    // for each D* group (s[i..j]), reverse ans[i..j + 1]
    int i = -1;
    int j = -1;

    while (true) {
      i = getNextIndex(s, 'D', j + 1);
      if (i == s.length())
        break;
      j = getNextIndex(s, 'I', i + 1);
      reverse(ans, i, j);
    }

    return ans;
  }

  private int getNextIndex(final String s, char c, int start) {
    for (int i = start; i < s.length(); ++i)
      if (s.charAt(i) == c)
        return i;
    return s.length();
  }

  private void reverse(int[] A, int l, int r) {
    while (l < r)
      swap(A, l++, r--);
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
