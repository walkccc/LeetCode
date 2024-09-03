class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    return accumulate(nums.begin(), nums.end(), 0,
                      [](int subtotal, unsigned num) {
      return subtotal + popcount(num);
    }) + (maxNum == 0 ? 0 : (int)log2(maxNum));
  }
};
