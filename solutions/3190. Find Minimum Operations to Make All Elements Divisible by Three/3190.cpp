class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    return ranges::count_if(nums, [](int num) { return num % 3 != 0; });
  }
};
