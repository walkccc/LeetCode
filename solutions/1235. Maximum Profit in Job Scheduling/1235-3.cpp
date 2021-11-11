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
    vector<Job> jobs;

    for (int i = 0; i < startTime.size(); ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    sort(begin(jobs), end(jobs), [](const auto& a, const auto& b) {
      return a.startTime < b.startTime;
    });

    return getMaxProfit(jobs);
  }

 private:
  int getMaxProfit(const vector<Job>& jobs) {
    int maxProfit = 0;
    auto compare = [](const Job& a, const Job& b) {
      return a.endTime > b.endTime;
    };
    // {endTime, profit}: min-heap sorted by endTime
    priority_queue<Job, vector<Job>, decltype(compare)> pq(compare);

    for (const auto& [s, e, p] : jobs) {
      while (!pq.empty() && s >= pq.top().endTime)
        maxProfit = max(maxProfit, pq.top().profit), pq.pop();
      pq.emplace(s, e, p + maxProfit);
    }

    while (!pq.empty())
      maxProfit = max(maxProfit, pq.top().profit), pq.pop();

    return maxProfit;
  }
};
