class Solution {
  public int minDays(int n) {
    if (n <= 1)
      return n;
    if (dp.containsKey(n))
      return dp.get(n);

    final int res = 1 + Math.min(minDays(n / 3) + n % 3, //
                                 minDays(n / 2) + n % 2);
    dp.put(n, res);
    return res;
  }

  private Map<Integer, Integer> dp = new HashMap<>();
}
