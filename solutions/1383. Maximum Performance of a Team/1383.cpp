class Solution {
 public:
  // Similar to 857. Minimum Cost to Hire K Workers
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    long speedSum = 0;
    // (efficiency[i], speed[i]) sorted by efficiency[i] in descending order
    vector<pair<int, int>> A;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < n; ++i)
      A.emplace_back(efficiency[i], speed[i]);

    ranges::sort(A, greater<>());

    for (const auto& [e, s] : A) {
      minHeap.push(s);
      speedSum += s;
      if (minHeap.size() > k)
        speedSum -= minHeap.top(), minHeap.pop();
      ans = max(ans, speedSum * e);
    }

    return ans % kMod;
  }
};
