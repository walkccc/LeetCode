class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    if (multiplier == 1)
      return nums;

    const int n = nums.size();
    const int maxNum = ranges::max(nums);
    vector<int> ans(n);
    using P = pair<int, int>;  // (nums[i], i)
    priority_queue<P, vector<P>, greater<>> minHeap;

    for (int i = 0; i < n; ++i)
      minHeap.emplace(nums[i], i);

    // Keep multiplying the minimum number as close as possible to the maximum
    // number in the array. After that, stop multiplying the minimum number
    // because it will be greater than the maximum number in the array and break
    // the circularity.
    while (k > 0 &&
           static_cast<long>(minHeap.top().first) * multiplier <= maxNum) {
      const auto [num, i] = minHeap.top();
      minHeap.pop();
      minHeap.emplace(num * multiplier, i);
      --k;
    }

    vector<pair<int, int>> sortedIndexedNums;
    while (!minHeap.empty())
      sortedIndexedNums.push_back(minHeap.top()), minHeap.pop();

    const int multipliesPerNum = k / n;
    const int remainingK = k % n;

    // Evenly distribute the remaining multiplications to each number by using
    // fast exponentiation.
    for (auto& [num, _] : sortedIndexedNums)
      num = (num * modPow(multiplier, multipliesPerNum)) % kMod;

    // Distribute the remaining multiplications to the minimum `remainingK`
    // numbers.
    for (int i = 0; i < remainingK; ++i)
      sortedIndexedNums[i].first =
          (static_cast<long>(sortedIndexedNums[i].first) * multiplier % kMod);

    for (const auto& [num, i] : sortedIndexedNums)
      ans[i] = num;

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
};
