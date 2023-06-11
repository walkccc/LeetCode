class Solution {
 public:
  int maximizeSum(vector<int>& nums, int k) {
    // If x = max(nums), ans = x + (x + 1) + .. + (x + k - 1).
    const int x = *max_element(begin(nums), end(nums));
    return x * k + k * (k - 1) / 2;
  }
};
