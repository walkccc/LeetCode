class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                             int k2) {
    const vector<int> diff = getDiff(nums1, nums2);
    int k = k1 + k2;
    if (accumulate(diff.begin(), diff.end(), 0LL) <= k)
      return 0;

    unordered_map<int, int> count;
    priority_queue<pair<int, int>> maxHeap;  // (num, freq)

    for (const int d : diff)
      if (d != 0)
        ++count[d];

    for (const auto& [num, freq] : count)
      maxHeap.emplace(num, freq);

    while (k > 0) {
      const auto [maxNum, maxNumFreq] = maxHeap.top();
      maxHeap.pop();
      // Buck decrease in this turn
      const int numDecreased = min(k, maxNumFreq);
      k -= numDecreased;
      if (maxNumFreq > numDecreased)
        maxHeap.emplace(maxNum, maxNumFreq - numDecreased);
      if (!maxHeap.empty() && maxHeap.top().first + 1 == maxNum) {
        const auto [secondMaxNum, secondMaxNumFreq] = maxHeap.top();
        maxHeap.pop();
        maxHeap.emplace(secondMaxNum, secondMaxNumFreq + numDecreased);
      } else if (maxNum > 1) {
        maxHeap.emplace(maxNum - 1, numDecreased);
      }
    }

    long long ans = 0;
    while (!maxHeap.empty()) {
      const auto [num, freq] = maxHeap.top();
      maxHeap.pop();
      ans += static_cast<long long>(num) * num * freq;
    }

    return ans;
  }

 private:
  vector<int> getDiff(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> diff;
    for (int i = 0; i < nums1.size(); ++i)
      diff.push_back(abs(nums1[i] - nums2[i]));
    return diff;
  }
};
