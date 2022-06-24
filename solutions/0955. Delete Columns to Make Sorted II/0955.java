class Solution {
  public int minDeletionSize(String[] A) {
    final int n = A[0].length();
    int ans = 0;
    // sorted[i] := true if A[i] < A[i + 1]
    boolean[] sorted = new boolean[A.length - 1];

    for (int j = 0; j < n; ++j) {
      int i;
      for (i = 0; i + 1 < A.length; ++i)
        if (!sorted[i] && A[i].charAt(j) > A[i + 1].charAt(j)) {
          ++ans;
          break;
        }
      // already compared each pair, update the sorted array if needed
      if (i + 1 == A.length)
        for (i = 0; i + 1 < A.length; ++i)
          sorted[i] = sorted[i] || A[i].charAt(j) < A[i + 1].charAt(j);
    }

    return ans;
  }
}
