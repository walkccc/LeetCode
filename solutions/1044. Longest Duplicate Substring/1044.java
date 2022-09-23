class Solution {
  public String longestDupSubstring(String s) {
    final int kMod = 1_000_000_007;
    final int n = s.length();
    int[] pows = new int[n];
    int bestStart = -1;
    int l = 1;
    int r = n;

    pows[0] = 1;
    for (int i = 1; i < n; ++i)
      pows[i] = (int) ((pows[i - 1] * 26L) % (long) kMod);

    while (l < r) {
      final int m = (l + r) / 2;
      final int start = getStart(s, m, pows, kMod);
      if (start == -1) {
        r = m;
      } else {
        bestStart = start;
        l = m + 1;
      }
    }

    if (bestStart == -1)
      return "";
    if (getStart(s, l, pows, kMod) == -1)
      return s.substring(bestStart, bestStart + l - 1);
    return s.substring(bestStart, bestStart + l);
  }

  // k := length of hashed substring
  private int getStart(final String s, int k, int[] pows, int kMod) {
    Map<Long, List<Integer>> hashedToStarts = new HashMap<>();
    long h = 0;

    // compute hash value of s[:k]
    for (int i = 0; i < k; ++i)
      h = ((h * 26) % kMod + val(s.charAt(i))) % kMod;
    hashedToStarts.put(h, new ArrayList<>());
    hashedToStarts.get(h).add(0);

    // compute rolling hash by Rabin Karp
    for (int i = k; i < s.length(); ++i) {
      final int startIndex = i - k + 1;
      h = ((h - (long) (pows[k - 1]) * val(s.charAt(i - k))) % kMod + kMod) % kMod;
      h = (h * 26 + val(s.charAt(i))) % kMod;
      if (hashedToStarts.containsKey(h)) {
        final String currSub = s.substring(startIndex, startIndex + k);
        for (final int start : hashedToStarts.get(h))
          if (s.substring(start, start + k).equals(currSub))
            return startIndex;
      }
      hashedToStarts.put(h, new ArrayList<>());
      hashedToStarts.get(h).add(startIndex);
    }

    return -1;
  }

  private int val(char c) {
    return c - 'a';
  }
}
