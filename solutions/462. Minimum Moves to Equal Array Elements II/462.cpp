class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    const int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
    const int median = nums[n / 2];
    return accumulate(nums.begin(), nums.end(), 0,
                      [&](int a, int b) { return a + abs(b - median); });
  }
};
