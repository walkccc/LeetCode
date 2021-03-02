class Solution {
  public int minKBitFlips(int[] A, int K) {
    int ans = 0;
    int flippedTime = 0;

    for (int r = 0; r < A.length; ++r) {
      if (r >= K && A[r - K] == 2)
        --flippedTime;
      if (flippedTime % 2 == A[r]) {
        if (r + K > A.length)
          return -1;
        ++ans;
        ++flippedTime;
        A[r] = 2;
      }
    }

    return ans;
  }
}
