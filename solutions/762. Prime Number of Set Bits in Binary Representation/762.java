class Solution {
  public int countPrimeSetBits(int left, int right) {
    // {2, 3, 5, 7, 11, 13, 17, 19}-th bits are 1s.
    // 0b10100010100010101100 = 665772
    final int magic = 665772;
    int ans = 0;

    for (int num = left; num <= right; ++num)
      if ((magic >> Integer.bitCount(num) & 1) == 1)
        ++ans;

    return ans;
  }
}
