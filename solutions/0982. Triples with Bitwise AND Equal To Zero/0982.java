class Solution {
  public int countTriplets(int[] A) {
    final int kMax = 1 << 16;
    int ans = 0;
    int[] count = new int[kMax]; // {A[i] & A[j]: times}

    for (final int a : A)
      for (final int b : A)
        ++count[a & b];

    for (final int a : A)
      for (int i = 0; i < kMax; ++i)
        if ((a & i) == 0)
          ans += count[i];

    return ans;
  }
}
