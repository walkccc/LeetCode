class Solution {
  public int minDeletionSize(String[] A) {
    final int n = A[0].length();
    int ans = 0;

    for (int j = 0; j < n; ++j)
      for (int i = 0; i + 1 < A.length; ++i)
        if (A[i].charAt(j) > A[i + 1].charAt(j)) {
          ++ans;
          break;
        }

    return ans;
  }
}
