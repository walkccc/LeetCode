class Solution {
 public:
  long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
    long ans = 0;
    long cost = 0;
    // Store (number, count) pairs in non-increasing order. The numbers in the
    // queue represent what nums[i..j] look like after adjustments.
    deque<pair<int, int>> dq;

    for (int i = nums.size() - 1, j = nums.size() - 1; i >= 0; --i) {
      const int num = nums[i];
      int count = 1;
      while (!dq.empty() && dq.back().first < num) {
        const auto [nextNum, nextCount] = dq.back();
        dq.pop_back();
        count += nextCount;
        // Adjust `nextNum`s to `num`.
        cost += static_cast<long>(num - nextNum) * nextCount;
      }
      dq.emplace_back(num, count);
      while (cost > k) {
        const auto [rightmostNum, rightmostCount] = dq.front();
        dq.pop_front();
        cost -= static_cast<long>(rightmostNum - nums[j--]);
        if (rightmostCount > 1)
          dq.emplace_front(rightmostNum, rightmostCount - 1);
      }
      ans += j - i + 1;
    }

    return ans;
  }
};
