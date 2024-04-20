class Solution {
  public int concatenatedBinary(int n) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    int numberOfBits = 0;

    for (int i = 1; i <= n; ++i) {
      if (Integer.bitCount(i) == 1)
        ++numberOfBits;
      ans = ((ans << numberOfBits) % kMod + i) % kMod;
    }

    return (int) ans;
  }
}
