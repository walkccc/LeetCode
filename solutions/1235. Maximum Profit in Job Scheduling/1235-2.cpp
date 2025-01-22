struct Job {
  int startTime;
  int endTime;
  int profit;
};

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    const int n = startTime.size();
    // dp[i] := the maximum profit to schedule jobs[i..n)
    vector<int> dp(n + 1);
    vector<Job> jobs;

    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    ranges::sort(jobs, ranges::less{},
                 [](const Job& job) { return job.startTime; });

    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    for (int i = n - 1; i >= 0; --i) {
      const int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
      const int pick = jobs[i].profit + dp[j];
      const int skip = dp[i + 1];
      dp[i] = max(pick, skip);
    }

    return dp[0];
  }

  int firstGreaterEqual(const vector<int>& A, int startFrom, int target) {
    return lower_bound(A.begin() + startFrom, A.end(), target) - A.begin();
  }
};
