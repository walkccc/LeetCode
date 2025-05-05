class Solution {
  public String minCostGoodCaption(String caption) {
    final int n = caption.length();
    if (n < 3)
      return "";

    final int MAX_COST = 1_000_000_000;
    int[][][] dp = new int[n][26][3];
    Arrays.stream(dp).forEach(A -> Arrays.stream(A).forEach(B -> Arrays.fill(B, MAX_COST)));
    // dp[i][j][k] := the minimum cost of caption[i..n - 1], where j is the last
    // letter used, and k is the count of consecutive letters
    for (char c = 'a'; c <= 'z'; ++c)
      dp[n - 1][c - 'a'][0] = Math.abs(caption.charAt(n - 1) - c);

    int minCost = MAX_COST;
    for (int i = n - 2; i >= 0; --i) {
      int newMinCost = MAX_COST;
      for (char c = 'a'; c <= 'z'; ++c) {
        final int j = c - 'a';
        final int changeCost = Math.abs(caption.charAt(i) - c);
        dp[i][j][0] = changeCost + minCost;
        dp[i][j][1] = changeCost + dp[i + 1][j][0];
        dp[i][j][2] = changeCost + Math.min(dp[i + 1][j][1], dp[i + 1][j][2]);
        newMinCost = Math.min(newMinCost, dp[i][j][2]);
      }
      minCost = newMinCost;
    }

    // Reconstruct the string.
    StringBuilder sb = new StringBuilder();
    int cost = MAX_COST;
    int letter = -1;

    // Find the initial best letter.
    for (int c = 25; c >= 0; --c)
      if (dp[0][c][2] <= cost) {
        letter = c;
        cost = dp[0][c][2];
      }

    // Add the initial triplet.
    cost -= appendLetter(caption, 0, (char) ('a' + letter), sb);
    cost -= appendLetter(caption, 1, (char) ('a' + letter), sb);
    cost -= appendLetter(caption, 2, (char) ('a' + letter), sb);

    // Build the rest of the string.
    for (int i = 3; i < n;) {
      // Check if we should switch to a new letter.
      final int nextLetter = getNextLetter(dp, i, cost);
      if (nextLetter < letter || Arrays.stream(dp[i][letter]).min().getAsInt() > cost) {
        letter = nextLetter;
        cost -= appendLetter(caption, i, (char) ('a' + letter), sb);
        cost -= appendLetter(caption, i + 1, (char) ('a' + letter), sb);
        cost -= appendLetter(caption, i + 2, (char) ('a' + letter), sb);
        i += 3;
      } else {
        cost -= appendLetter(caption, i, (char) ('a' + letter), sb);
        i += 1;
      }
    }

    return sb.toString();
  }

  private int getNextLetter(int[][][] dp, int i, int cost) {
    int nextLetter = 26;
    for (int c = 25; c >= 0; --c)
      if (cost == dp[i][c][2])
        nextLetter = c;
    return nextLetter;
  }

  private int appendLetter(String caption, int i, char letter, StringBuilder sb) {
    sb.append(letter);
    return Math.abs(caption.charAt(i) - letter);
  }
}
