class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    double ans = DBL_MAX;
    int qualitySum = 0;
    // (wagePerQuality, quality) sorted by wagePerQuality
    vector<pair<double, int>> workers;
    priority_queue<int> maxHeap;

    for (int i = 0; i < quality.size(); ++i)
      workers.emplace_back((double)wage[i] / quality[i], quality[i]);

    ranges::sort(workers);

    for (const auto& [wagePerQuality, q] : workers) {
      maxHeap.push(q);
      qualitySum += q;
      if (maxHeap.size() > k)
        qualitySum -= maxHeap.top(), maxHeap.pop();
      if (maxHeap.size() == k)
        ans = min(ans, qualitySum * wagePerQuality);
    }

    return ans;
  }
};
