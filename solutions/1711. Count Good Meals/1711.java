class Solution {
  public int countPairs(int[] deliciousness) {
    final int kMod = 1_000_000_007;
    final int kMaxBit = 20 + 1;
    final int kMaxPower = (int) Math.pow(2, kMaxBit);
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int d : deliciousness) {
      for (int power = 1; power <= kMaxPower; power *= 2) {
        ans += count.getOrDefault(power - d, 0);
        ans %= kMod;
      }
      count.merge(d, 1, Integer::sum);
    }

    return ans;
  }
}
