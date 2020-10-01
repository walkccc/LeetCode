class Solution {
  public int binaryGap(int N) {
    int ans = 0;
    int prevOneIndex = 30;

    for (int n = N, i = 0; n > 0; n >>= 1, ++i)
      if (n % 2 == 1) {
        ans = Math.max(ans, i - prevOneIndex);
        prevOneIndex = i;
      }

    return ans;
  }
}