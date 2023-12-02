class Solution {
 public:
  long long kSum(vector<int>& nums, int k) {
    const long long maxSum = getMaxSum(nums);
    const vector<int> absNums = getAbsNums(nums);
    long long ans = maxSum;
    // (the next maximum sum, the next index i)
    using P = pair<long long, int>;
    priority_queue<P> maxHeap;
    maxHeap.emplace(maxSum - absNums[0], 0);

    for (int j = 0; j < k - 1; ++j) {
      const auto [nextMaxSum, i] = maxHeap.top();
      maxHeap.pop();
      ans = nextMaxSum;
      if (i + 1 < absNums.size()) {
        maxHeap.emplace(nextMaxSum - absNums[i + 1], i + 1);
        maxHeap.emplace(nextMaxSum - absNums[i + 1] + absNums[i], i + 1);
      }
    }

    return ans;
  }

 private:
  long long getMaxSum(const vector<int>& nums) {
    long long maxSum = 0;
    for (const int num : nums)
      if (num > 0)
        maxSum += num;
    return maxSum;
  }

  vector<int> getAbsNums(const vector<int>& nums) {
    vector<int> absNums;
    for (const int num : nums)
      absNums.push_back(abs(num));
    ranges::sort(absNums);
    return absNums;
  }
};
