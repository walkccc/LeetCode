class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> ans(k);
    unordered_map<int, unordered_set<int>> idToTimes;

    for (const vector<int>& log : logs)
      idToTimes[log[0]].insert(log[1]);

    for (const auto& [_, mins] : idToTimes)
      ++ans[mins.size() - 1];

    return ans;
  }
};
