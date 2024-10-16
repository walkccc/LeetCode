class Solution {
 public:
  int minimumTimeRequired(std::vector<int>& jobs, int k) {
    int ans = accumulate(jobs.begin(), jobs.end(), 0);
    vector<int> times(k);

    ranges::sort(jobs, greater<>());
    dfs(jobs, 0, times, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& jobs, int s, vector<int>& times, int& ans) {
    if (s == jobs.size()) {
      ans = min(ans, ranges::max(times));
      return;
    }
    for (int i = 0; i < times.size(); ++i) {
      if (times[i] + jobs[s] >= ans)
        continue;
      times[i] += jobs[s];
      dfs(jobs, s + 1, times, ans);
      times[i] -= jobs[s];
      if (times[i] == 0)
        return;
    }
  };
};
