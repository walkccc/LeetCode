class Solution {
  public int numSubarrayBoundedMax(int[] A, int L, int R) {
    int ans = 0;
    int l = -1;
    int r = -1;

    for (int i = 0; i < A.length; ++i) {
      if (A[i] > R) // handle reset value
        l = i;
      if (A[i] >= L) // handle reset and needed value
        r = i;
      ans += r - l;
    }

    return ans;
  }
}
