class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> ans(k);
    unordered_map<int, unordered_set<int>> idToTimes;

    for (const auto& l : logs)
      idToTimes[l[0]].insert(l[1]);

    for (const auto& [_, mins] : idToTimes)
      ++ans[mins.size() - 1];

    return ans;
  }
};
