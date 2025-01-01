class Solution {
  public int bestTeamScore(int[] scores, int[] ages) {
    record Player(int age, int score) {}
    final int n = scores.length;
    Player[] players = new Player[n];
    // dp[i] := the maximum score of choosing the players[0..i] with the players[i] being selected
    int[] dp = new int[n];

    for (int i = 0; i < n; ++i)
      players[i] = new Player(ages[i], scores[i]);

    Arrays.sort(players,
                (a, b) //
                -> a.age == b.age ? Integer.compare(b.score, a.score)
                                  : Integer.compare(b.age, a.age));

    for (int i = 0; i < n; ++i) {
      // For each player, choose it first.
      dp[i] = players[i].score;
      // players[j].age >= players[i].age since we sort in descending order.
      // So, we only have to check that players[j].score >= players[i].score.
      for (int j = 0; j < i; ++j)
        if (players[j].score >= players[i].score)
          dp[i] = Math.max(dp[i], dp[j] + players[i].score);
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
