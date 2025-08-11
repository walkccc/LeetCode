class Solution {
  public String longestDupSubstring(String s) {
    final int n = s.length();
    int[] pows = new int[n];
    int bestStart = -1;
    int l = 1;
    int r = n;

    pows[0] = 1;
    for (int i = 1; i < n; ++i)
      pows[i] = (int) (pows[i - 1] * BASE % HASH);

    while (l < r) {
      final int m = (l + r) / 2;
      final int start = getStart(s, m, pows);
      if (start == -1) {
        r = m;
      } else {
        bestStart = start;
        l = m + 1;
      }
    }

    if (bestStart == -1)
      return "";
    if (getStart(s, l, pows) == -1)
      return s.substring(bestStart, bestStart + l - 1);
    return s.substring(bestStart, bestStart + l);
  }

  private static final long BASE = 26;
  private static final long HASH = 1_000_000_007;

  private static int val(char c) {
    return c - 'a';
  }

  // k := the length of the substring to be hashed
  private int getStart(final String s, int k, int[] pows) {
    Map<Long, List<Integer>> hashToStarts = new HashMap<>();
    long h = 0;

    // Compute the hash value of s[:k].
    for (int i = 0; i < k; ++i)
      h = (h * BASE % HASH + val(s.charAt(i))) % HASH;
    hashToStarts.put(h, new ArrayList<>());
    hashToStarts.get(h).add(0);

    // Compute the rolling hash by Rabin Karp.
    for (int i = k; i < s.length(); ++i) {
      final int startIndex = i - k + 1;
      h = ((h - (long) (pows[k - 1]) * val(s.charAt(i - k))) % HASH + HASH) % HASH;
      h = (h * BASE + val(s.charAt(i))) % HASH;
      if (hashToStarts.containsKey(h)) {
        final String currSub = s.substring(startIndex, startIndex + k);
        for (final int start : hashToStarts.get(h))
          if (s.substring(start, start + k).equals(currSub))
            return startIndex;
      }
      hashToStarts.put(h, new ArrayList<>());
      hashToStarts.get(h).add(startIndex);
    }

    return -1;
  }
}
