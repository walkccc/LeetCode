class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    return __builtin_popcount(k ^ xors);
  }
};
