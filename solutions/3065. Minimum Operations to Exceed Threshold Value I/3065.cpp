class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    return ranges::count_if(nums, [k](int num) { return num < k; });
  }
};
