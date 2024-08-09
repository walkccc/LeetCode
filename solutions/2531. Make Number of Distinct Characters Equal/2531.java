class Solution {
  public boolean isItPossible(String word1, String word2) {
    final int[] count1 = getCount(word1);
    final int[] count2 = getCount(word2);
    final int distinct1 = getDistinct(count1);
    final int distinct2 = getDistinct(count2);

    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        if (count1[i] == 0 || count2[j] == 0)
          continue;
        if (i == j) {
          // Swapping the same letters won't change the number of distinct
          // letters in each string, so just check if `distinct1 == distinct2`.
          if (distinct1 == distinct2)
            return true;
          continue;
        }
        // The calculation is meaningful only when i != j.
        // Swap ('a' + i) in word1 with ('a' + j) in word2.
        final int distinctAfterSwap1 =
            distinct1 - (count1[i] == 1 ? 1 : 0) + (count1[j] == 0 ? 1 : 0);
        final int distinctAfterSwap2 =
            distinct2 - (count2[j] == 1 ? 1 : 0) + (count2[i] == 0 ? 1 : 0);
        if (distinctAfterSwap1 == distinctAfterSwap2)
          return true;
      }

    return false;
  }

  private int[] getCount(final String s) {
    int[] count = new int[26];
    for (final char c : s.toCharArray())
      ++count[c - 'a'];
    return count;
  }

  private int getDistinct(int[] count) {
    return (int) Arrays.stream(count).filter(c -> c > 0).count();
  }
}
