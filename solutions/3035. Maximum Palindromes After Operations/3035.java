class Solution {
  public int maxPalindromesAfterOperations(String[] words) {
    int ans = 0;
    int pairs = getPairs(words);

    for (final int length : getSortedLengths(words)) {
      final int neededPairs = length / 2;
      if (pairs < neededPairs)
        return ans;
      ++ans;
      pairs -= neededPairs;
    }

    return ans;
  }

  private int getPairs(String[] words) {
    int pairs = 0;
    Map<Character, Integer> count = new HashMap<>();

    for (final String word : words)
      for (final char c : word.toCharArray())
        count.merge(c, 1, Integer::sum);

    for (final int freq : count.values())
      pairs += freq / 2;

    return pairs;
  }

  private int[] getSortedLengths(String[] words) {
    int[] lengths = new int[words.length];
    for (int i = 0; i < words.length; ++i)
      lengths[i] = words[i].length();
    Arrays.sort(lengths);
    return lengths;
  }
}
