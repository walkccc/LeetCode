class Solution {
  public int possibleStringCount(String word, int k) {
    List<Integer> groups = getConsecutiveLetters(word);
    final int totalCombinations =
        (int) groups.stream().mapToLong(Integer::longValue).reduce(1L, (a, b) -> a * b % kMod);
    if (k <= groups.size())
      return totalCombinations;

    // dp[j] := the number of ways to form strings of length j using
    // groups[0..i]
    int[] dp = new int[k];
    dp[0] = 1; // Base case: empty string

    for (int i = 0; i < groups.size(); ++i) {
      int[] newDp = new int[k];
      int windowSum = 0;
      int group = groups.get(i);
      for (int j = i; j < k; ++j) {
        newDp[j] = (newDp[j] + windowSum) % kMod;
        windowSum = (windowSum + dp[j]) % kMod;
        if (j >= group)
          windowSum = (windowSum - dp[j - group] + kMod) % kMod;
      }
      dp = newDp;
    }

    final int invalidCombinations = Arrays.stream(dp).reduce(0, (a, b) -> (a + b) % kMod);
    return (totalCombinations - invalidCombinations + kMod) % kMod;
  }

  private static final int kMod = 1_000_000_007;

  // Returns consecutive identical letters in the input string.
  // e.g. "aabbbc" -> [2, 3, 1].
  private List<Integer> getConsecutiveLetters(final String word) {
    List<Integer> groups = new ArrayList<>();
    int group = 1;
    for (int i = 1; i < word.length(); ++i)
      if (word.charAt(i) == word.charAt(i - 1)) {
        ++group;
      } else {
        groups.add(group);
        group = 1;
      }
    groups.add(group);
    return groups;
  }
}
