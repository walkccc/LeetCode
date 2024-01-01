class Solution {
  public int numMatchingSubseq(String s, String[] words) {
    int ans = 0;
    // [(i, j)] := words[i] and the letter words[i][j] is waiting for
    List<Pair<Integer, Integer>>[] bucket = new List[26];

    for (int i = 0; i < 26; ++i)
      bucket[i] = new ArrayList<>();

    // For each word, it's waiting for word[0].
    for (int i = 0; i < words.length; ++i)
      bucket[words[i].charAt(0) - 'a'].add(new Pair<>(i, 0));

    for (final char c : s.toCharArray()) {
      // Let prevBucket = bucket[c] and clear bucket[c].
      List<Pair<Integer, Integer>> prevBucket = bucket[c - 'a'];
      bucket[c - 'a'] = new ArrayList<>();
      for (Pair<Integer, Integer> pair : prevBucket) {
        final int i = pair.getKey();
        final int j = pair.getValue() + 1;
        // All the letters in words[i] are matched.
        if (j == words[i].length())
          ++ans;
        else
          bucket[words[i].charAt(j) - 'a'].add(new Pair<>(i, j));
      }
    }

    return ans;
  }
}
