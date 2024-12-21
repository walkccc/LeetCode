public class Solution {
  public int countKSubsequencesWithMaxBeauty(String s, int k) {
    Map<Character, Integer> count = new HashMap<>();
    for (final char c : s.toCharArray())
      count.merge(c, 1, Integer::sum);
    if (count.size() < k)
      return 0;

    long ans = 1;

    for (Pair<Integer, Integer> pair : getFreqCountPairs(count)) {
      final int fc = pair.getKey();
      final int numOfChars = pair.getValue();
      if (numOfChars >= k) {
        ans *= nCk(numOfChars, k) * modPow(fc, k);
        return (int) (ans % kMod);
      }
      ans *= modPow(fc, numOfChars);
      ans %= kMod;
      k -= numOfChars;
    }

    return (int) ans;
  }

  private static final int kMod = 1_000_000_007;

  private List<Pair<Integer, Integer>> getFreqCountPairs(Map<Character, Integer> count) {
    // freqCount := (f(c), # of chars with f(c))
    Map<Integer, Integer> freqCount = new HashMap<>();
    for (final int value : count.values())
      freqCount.merge(value, 1, Integer::sum);
    List<Pair<Integer, Integer>> freqCountPairs = new ArrayList<>();
    for (Map.Entry<Integer, Integer> entry : freqCount.entrySet())
      freqCountPairs.add(new Pair<>(entry.getKey(), entry.getValue()));
    freqCountPairs.sort((a, b) -> b.getKey().compareTo(a.getKey()));
    return freqCountPairs;
  }

  private long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      res = res * (n - i + 1) / i;
    return res;
  }

  private int modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return (int) (x * modPow(x % kMod, (n - 1)) % kMod);
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
}
