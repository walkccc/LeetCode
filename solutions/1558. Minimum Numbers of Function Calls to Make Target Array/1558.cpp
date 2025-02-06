class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int mx = ranges::max(nums);
    return accumulate(nums.begin(), nums.end(), 0,
                      [](int subtotal, unsigned num) {
      return subtotal + popcount(num);
    }) + (mx == 0 ? 0 : static_cast<int>(log2(mx)));
  }
};
