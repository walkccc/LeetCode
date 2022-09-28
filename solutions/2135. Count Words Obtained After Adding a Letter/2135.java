class Solution {
  public int wordCount(String[] startWords, String[] targetWords) {
    int ans = 0;
    Set<Integer> seen = Arrays.stream(startWords).map(this::getMask).collect(Collectors.toSet());

    for (final String w : targetWords) {
      final int mask = getMask(w);
      for (final char c : w.toCharArray())
        // toggle one character
        if (seen.contains(mask ^ 1 << c - 'a')) {
          ++ans;
          break;
        }
    }

    return ans;
  }

  private int getMask(final String s) {
    int mask = 0;
    for (final char c : s.toCharArray())
      mask ^= 1 << c - 'a';
    return mask;
  }
}
