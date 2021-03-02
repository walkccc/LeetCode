class Leaderboard {
 public:
  void addScore(int playerId, int score) {
    idToScore[playerId] += score;
  }

  int top(int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    for (const auto& [id, score] : idToScore) {
      pq.push(score);
      if (pq.size() > K)
        pq.pop();
    }

    while (!pq.empty())
      ans += pq.top(), pq.pop();

    return ans;
  }

  void reset(int playerId) {
    idToScore.erase(playerId);
  }

 private:
  unordered_map<int, int> idToScore;
};
