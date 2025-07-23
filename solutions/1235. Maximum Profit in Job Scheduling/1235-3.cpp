struct Job {
  int startTime;
  int endTime;
  int profit;
};

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    vector<Job> jobs;

    for (int i = 0; i < startTime.size(); ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    ranges::sort(jobs, ranges::less{},
                 [](const Job& job) { return job.startTime; });

    return getMaxProfit(jobs);
  }

 private:
  int getMaxProfit(const vector<Job>& jobs) {
    int maxProfit = 0;
    auto compare = [](const Job& a, const Job& b) {
      return a.endTime > b.endTime;
    };
    priority_queue<Job, vector<Job>, decltype(compare)> minHeap(compare);

    for (const auto& [s, e, p] : jobs) {
      while (!minHeap.empty() && s >= minHeap.top().endTime)
        maxProfit = max(maxProfit, minHeap.top().profit), minHeap.pop();
      minHeap.emplace(s, e, p + maxProfit);
    }

    while (!minHeap.empty())
      maxProfit = max(maxProfit, minHeap.top().profit), minHeap.pop();

    return maxProfit;
  }
};
