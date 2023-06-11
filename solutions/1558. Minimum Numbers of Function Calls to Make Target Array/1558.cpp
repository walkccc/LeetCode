class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int maxNum = *max_element(begin(nums), end(nums));
    return accumulate(
               begin(nums), end(nums), 0,
               [](int subtotal, int num) {
      return subtotal + __builtin_popcount(num);
               }) +
        (maxNum == 0 ? 0 : (int)log2(maxNum));
  }
};
