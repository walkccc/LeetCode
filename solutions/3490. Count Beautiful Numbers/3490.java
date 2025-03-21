class Solution {
  public int beautifulNumbers(int l, int r) {
    return count(String.valueOf(r), 0, /*tight=*/true, /*isLeadingZero=*/true,
                 /*hasZero=*/false, /*sum=*/0, /*prod=*/1, new HashMap<>()) -
        count(String.valueOf(l - 1), 0, /*tight=*/true, /*isLeadingZero=*/true,
              /*hasZero=*/false, /*sum=*/0, /*prod=*/1, new HashMap<>());
  }

  private int count(final String s, int i, boolean tight, boolean isLeadingZero, boolean hasZero,
                    int sum, int prod, Map<String, Integer> mem) {
    if (i == s.length()) {
      if (isLeadingZero)
        return 0;
      return (hasZero || prod % sum == 0) ? 1 : 0;
    }
    final String key = hash(i, tight, isLeadingZero, hasZero, sum, prod);
    if (!isLeadingZero && hasZero && !tight) {
      final int val = (int) Math.pow(10, s.length() - i);
      mem.put(key, val);
      return val;
    }
    if (mem.containsKey(key))
      return mem.get(key);

    int res = 0;
    final int maxDigit = tight ? s.charAt(i) - '0' : 9;

    for (int d = 0; d <= maxDigit; ++d) {
      final boolean nextTight = tight && (d == maxDigit);
      final boolean nextIsLeadingZero = isLeadingZero && d == 0;
      final boolean nextHasZero = !nextIsLeadingZero && d == 0;
      final int nextProd = nextIsLeadingZero ? 1 : prod * d;
      res += count(s, i + 1, nextTight, nextIsLeadingZero, nextHasZero, sum + d, nextProd, mem);
    }

    mem.put(key, res);
    return res;
  }

  private String hash(int i, boolean tight, boolean isLeadingZero, boolean hasZero, int sum,
                      int prod) {
    return i + "_" + (tight ? "1" : "0") + "_" + (isLeadingZero ? "1" : "0") + "_" +
        (hasZero ? "1" : "0") + "_" + sum + "_" + prod;
  }
}
