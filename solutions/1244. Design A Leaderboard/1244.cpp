class Leaderboard {
 public:
  void addScore(int playerId, int score) {
    idToScore[playerId] += score;
  }

  int top(int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const auto& [id, score] : idToScore) {
      minHeap.push(score);
      if (minHeap.size() > K)
        minHeap.pop();
    }

    while (!minHeap.empty())
      ans += minHeap.top(), minHeap.pop();

    return ans;
  }

  void reset(int playerId) {
    idToScore.erase(playerId);
  }

 private:
  unordered_map<int, int> idToScore;
};
