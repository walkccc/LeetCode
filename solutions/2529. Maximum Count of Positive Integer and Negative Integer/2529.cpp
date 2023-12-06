class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    return max(ranges::count_if(nums, [](int num) { return num > 0; }),
               ranges::count_if(nums, [](int num) { return num < 0; }));
  }
};
