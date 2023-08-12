class Solution {
 public:
  int isWinner(vector<int>& player1, vector<int>& player2) {
    const int score1 = getScore(player1);
    const int score2 = getScore(player2);
    if (score1 > score2)
      return 1;
    if (score2 > score1)
      return 2;
    return 0;
  }

 private:
  int getScore(const vector<int>& player) {
    constexpr int kInvalid = -3;
    int score = 0;
    int last10 = kInvalid;
    for (int i = 0; i < player.size(); ++i) {
      score += i - last10 > 2 ? player[i] : player[i] * 2;
      if (player[i] == 10)
        last10 = i;
    }
    return score;
  }
};
