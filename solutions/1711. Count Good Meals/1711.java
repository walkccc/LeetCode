class Solution {
  public int countPairs(int[] deliciousness) {
    final int MOD = 1_000_000_007;
    final int MAX_BIT = 20 + 1;
    final int MAX_POWER = (int) Math.pow(2, MAX_BIT);
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int d : deliciousness) {
      for (int power = 1; power <= MAX_POWER; power *= 2) {
        ans += count.getOrDefault(power - d, 0);
        ans %= MOD;
      }
      count.merge(d, 1, Integer::sum);
    }

    return ans;
  }
}
