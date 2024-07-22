class Solution {
  public int isWinner(int[] player1, int[] player2) {
    final int score1 = getScore(player1);
    final int score2 = getScore(player2);
    if (score1 > score2)
      return 1;
    if (score2 > score1)
      return 2;
    return 0;
  }

  private int getScore(int[] player) {
    final int kInvalid = -3;
    int score = 0;
    int last10 = kInvalid;
    for (int i = 0; i < player.length; ++i) {
      score += i - last10 > 2 ? player[i] : player[i] * 2;
      if (player[i] == 10)
        last10 = i;
    }
    return score;
  }
}
