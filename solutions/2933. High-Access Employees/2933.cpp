class Solution {
 public:
  vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_set<string> ans;

    ranges::sort(access_times);

    for (int i = 0; i + 2 < access_times.size(); ++i) {
      const string& name = access_times[i][0];
      if (ans.count(name))
        continue;
      if (name != access_times[i + 2][0])
        continue;
      if (stoi(access_times[i + 2][1]) - stoi(access_times[i][1]) < 100)
        ans.insert(name);
    }

    return {ans.begin(), ans.end()};
  }
};
