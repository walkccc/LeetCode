class Solution {
 public:
  int minMoves(vector<int>& nums) {
    const int mn = ranges::min(nums);
    return accumulate(nums.begin(), nums.end(), 0, [&](int subtotal, int num) {
      return subtotal + (num - mn);
    });
  }
};
