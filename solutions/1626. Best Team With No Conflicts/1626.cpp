struct Player {
  int age;
  int score;
  Player(int age, int score) : age(age), score(score) {}
};

class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    const int n = scores.size();
    vector<Player> players;
    // dp[i] := the maximum score of choosing the players[0..i] with the
    // players[i] being selected
    vector<int> dp(n);

    for (int i = 0; i < n; ++i)
      players.emplace_back(ages[i], scores[i]);

    ranges::sort(players, [](const Player& a, const Player& b) {
      return a.age == b.age ? a.score > b.score : a.age > b.age;
    });

    for (int i = 0; i < n; ++i) {
      // For each player, choose it first.
      dp[i] = players[i].score;
      // players[j].age >= players[i].age since we sort in descending order.
      // So, we only have to check that players[j].score >= players[i].score.
      for (int j = 0; j < i; ++j)
        if (players[j].score >= players[i].score)
          dp[i] = max(dp[i], dp[j] + players[i].score);
    }

    return ranges::max(dp);
  }
};
