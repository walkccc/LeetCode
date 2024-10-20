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
    vector<int> mem(n + 1);
    vector<Job> jobs;

    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    ranges::sort(jobs, ranges::less{},
                 [](const Job& job) { return job.startTime; });

    // Will use binary search to find the first available start time.
    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    return jobScheduling(jobs, startTime, 0, mem);
  }

 private:
  // Returns the maximum profit to schedule jobs[i..n).
  int jobScheduling(const vector<Job>& jobs, const vector<int>& startTime,
                    int i, vector<int>& mem) {
    if (i == jobs.size())
      return 0;
    if (mem[i] > 0)
      return mem[i];

    const int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
    const int pick = jobs[i].profit + jobScheduling(jobs, startTime, j, mem);
    const int skip = jobScheduling(jobs, startTime, i + 1, mem);
    return mem[i] = max(pick, skip);
  }

  int firstGreaterEqual(const vector<int>& A, int startFrom, int target) {
    return lower_bound(A.begin() + startFrom, A.end(), target) - A.begin();
  }
};
