class Solution {
 public:
  int minLengthAfterRemovals(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<int, int> count;
    int maxFreq = 0;

    for (const int num : nums)
      ++count[num];

    for (const auto& [_, freq] : count)
      maxFreq = max(maxFreq, freq);

    // The number with the maximum frequency cancel all the other numbers.
    if (maxFreq <= n / 2)
      return n % 2;
    // The number with the maximum frequency cancel all the remaining numbers.
    return maxFreq - (n - maxFreq);
  }
};
