class Solution {
  public int minimumDeletions(String word, int k) {
    int ans = Integer.MAX_VALUE;
    int count[] = new int[26];

    for (final char c : word.toCharArray())
      ++count[c - 'a'];

    for (final int minFreq : count) {
      int deletions = 0;
      for (final int freq : count)
        if (freq < minFreq) // Delete all the letters with smaller frequency.
          deletions += freq;
        else // Delete letters with exceeding frequency.
          deletions += Math.max(0, freq - (minFreq + k));
      ans = Math.min(ans, deletions);
    }

    return ans;
  }
}
