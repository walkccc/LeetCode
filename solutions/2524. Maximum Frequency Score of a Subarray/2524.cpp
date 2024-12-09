class Solution {
 public:
  int maxFrequencyScore(vector<int>& nums, int k) {
    unordered_map<int, int> count;

    for (int i = 0; i < k; ++i)
      ++count[nums[i]];

    int sum = getInitialSum(count);
    int ans = sum;

    for (int i = k; i < nums.size(); ++i) {
      // Remove the leftmost number that's out-of-window.
      const int leftNum = nums[i - k];
      sum = (sum - modPow(leftNum, count[leftNum]) + kMod) % kMod;
      // After decreasing its frequency, if it's still > 0, then add it back.
      if (--count[leftNum] > 0)
        sum = (sum + modPow(leftNum, count[leftNum])) % kMod;
      // Otherwise, remove it from the count map.
      else
        count.erase(leftNum);
      // Add the current number. Similarly, remove the current score like above.
      const int rightNum = nums[i];
      if (count[rightNum] > 0)
        sum = (sum - modPow(rightNum, count[rightNum]) + kMod) % kMod;
      sum = (sum + modPow(rightNum, ++count[rightNum])) % kMod;
      ans = max(ans, sum);
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int getInitialSum(const unordered_map<int, int>& count) {
    long sum = 0;
    for (const auto& [num, freq] : count)
      sum = (sum + modPow(num, freq)) % kMod;
    return sum;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
