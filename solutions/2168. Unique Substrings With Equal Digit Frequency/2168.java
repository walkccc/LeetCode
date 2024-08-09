class Solution {
  public int equalDigitFrequency(String s) {
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < s.length(); ++i)
      for (int j = i; j < s.length(); ++j)
        if (isUnique(s, i, j))
          seen.add(getRollingHash(s, i, j));

    return seen.size();
  }

  private static final int power = 11;
  private static final int kMod = 1_000_000_007;

  private boolean isUnique(final String s, int i, int j) {
    int[] count = new int[10];
    int unique = 0;
    for (int k = i; k <= j; ++k)
      if (++count[s.charAt(k) - '0'] == 1)
        ++unique;
    final int maxCount = Arrays.stream(count).max().getAsInt();
    return maxCount * unique == j - i + 1;
  }

  private int getRollingHash(final String s, int i, int j) {
    long hash = 0;
    for (int k = i; k <= j; ++k)
      hash = (hash * power + val(s.charAt(k))) % kMod;
    return (int) hash;
  }

  private int val(char c) {
    return c - '0' + 1;
  }
}
