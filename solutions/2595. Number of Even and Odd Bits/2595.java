class Solution {
  public int[] evenOddBit(int n) {
    int[] ans = new int[2];
    int i = 0; // 0 := even, 1 := odd

    while (n > 0) {
      ans[i] += n & 1;
      n >>= 1;
      i ^= 1;
    }

    return ans;
  }
}
