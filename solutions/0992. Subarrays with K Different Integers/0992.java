class Solution {
  public int subarraysWithKDistinct(int[] A, int K) {
    return subarraysWithAtMostKDistinct(A, K) - subarraysWithAtMostKDistinct(A, K - 1);
  }

  private int subarraysWithAtMostKDistinct(int[] A, int K) {
    int ans = 0;
    int[] count = new int[A.length + 1];

    for (int l = 0, r = 0; r < A.length; ++r) {
      if (++count[A[r]] == 1)
        --K;
      while (K == -1)
        if (--count[A[l++]] == 0)
          ++K;
      ans += r - l + 1; // A[l..r], A[l + 1..r], ..., A[r]
    }

    return ans;
  }
}
