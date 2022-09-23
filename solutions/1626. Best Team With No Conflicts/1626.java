class Player {
  public int age;
  public int score;
  public Player(int age, int score) {
    this.age = age;
    this.score = score;
  }
};

class Solution {
  public int bestTeamScore(int[] scores, int[] ages) {
    final int n = scores.length;
    Player[] players = new Player[n];
    // dp[i] := max score of choosing players[0..i] w/ players[i] being selected
    int[] dp = new int[n];

    for (int i = 0; i < n; ++i)
      players[i] = new Player(ages[i], scores[i]);

    Arrays.sort(players, (a, b) -> a.age == b.age ? b.score - a.score : b.age - a.age);

    for (int i = 0; i < n; ++i) {
      // for each player, we choose it first
      dp[i] = players[i].score;
      // players[j].age >= players[i].age since we sort in descending order
      // so we only have to check that
      // players[j].score >= players[i].score
      for (int j = 0; j < i; ++j)
        if (players[j].score >= players[i].score)
          dp[i] = Math.max(dp[i], dp[j] + players[i].score);
    }

    return Arrays.stream(dp).max().getAsInt();
  }
}
