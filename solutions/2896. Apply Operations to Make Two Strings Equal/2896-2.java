class Solution {
  public int minOperations(String s1, String s2, int x) {
    List<Integer> diffIndices = getDiffIndices(s1, s2);
    if (diffIndices.isEmpty())
      return 0;
    // It's impossible to make two strings equal if there are odd number of
    // differences.
    if (diffIndices.size() % 2 == 1)
      return -1;

    double[] dp = new double[diffIndices.size() + 1];
    Arrays.fill(dp, Double.MAX_VALUE);
    dp[diffIndices.size()] = 0;
    dp[diffIndices.size() - 1] = x / 2.0;

    for (int i = diffIndices.size() - 2; i >= 0; --i)
      dp[i] = Math.min(dp[i + 1] + x / 2.0, //
                       dp[i + 2] + diffIndices.get(i + 1) - diffIndices.get(i));

    return (int) dp[0];
  }

  private List<Integer> getDiffIndices(final String s1, final String s2) {
    List<Integer> diffIndices = new ArrayList<>();
    for (int i = 0; i < s1.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        diffIndices.add(i);
    return diffIndices;
  }
}
