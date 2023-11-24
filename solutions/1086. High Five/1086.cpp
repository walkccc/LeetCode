class Solution {
 public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    vector<vector<int>> ans;
    map<int, priority_queue<int, vector<int>, greater<int>>> idToScores;

    for (const vector<int>& item : items) {
      const int id = item[0];
      const int score = item[1];
      auto& scores = idToScores[id];
      scores.push(score);
      if (scores.size() > 5)
        scores.pop();
    }

    for (auto& [id, scores] : idToScores) {
      int sum = 0;
      while (!scores.empty())
        sum += scores.top(), scores.pop();
      ans.push_back({id, sum / 5});
    }

    return ans;
  }
};
