struct Job {
  int startTime;
  int endTime;
  int profit;
  Job(int startTime, int endTime, int profit)
      : startTime(startTime), endTime(endTime), profit(profit) {}
};

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    const int n = startTime.size();
    // dp[i] := the maximum profit to schedule jobs[i..n)
    dp.resize(n + 1);
    vector<Job> jobs;

    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    ranges::sort(jobs, [](const auto& a, const auto& b) {
      return a.startTime < b.startTime;
    });

    // Will use binary search to find the first available startTime
    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    return jobScheduling(jobs, startTime, 0);
  }

 private:
  vector<int> dp;

  int jobScheduling(const vector<Job>& jobs, const vector<int>& startTime,
                    int i) {
    if (i == jobs.size())
      return 0;
    if (dp[i] > 0)
      return dp[i];

    const int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
    const int pick = jobs[i].profit + jobScheduling(jobs, startTime, j);
    const int skip = jobScheduling(jobs, startTime, i + 1);
    return dp[i] = max(pick, skip);
  }

  int firstGreaterEqual(const vector<int>& A, int startFrom, int target) {
    return lower_bound(A.begin() + startFrom, A.end(), target) - A.begin();
  }
};
