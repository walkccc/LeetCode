class Solution {
 public:
  int minimumTime(vector<int>& jobs, vector<int>& workers) {
    int ans = 0;

    ranges::sort(jobs);
    ranges::sort(workers);

    for (int i = 0; i < jobs.size(); ++i)
      ans = max(ans, (jobs[i] - 1) / workers[i] + 1);

    return ans;
  }
};
