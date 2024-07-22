class Solution {
  public int concatenatedBinary(int n) {
    final int kMod = 1_000_000_007;
    long ans = 0;

    for (int i = 1; i <= n; ++i)
      ans = ((ans << numberOfBits(i)) % kMod + i) % kMod;

    return (int) ans;
  }

  private int numberOfBits(int n) {
    return (int) (Math.log(n) / Math.log(2)) + 1;
  }
}
