class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    return max(
        count_if(nums.begin(), nums.end(), [](int num) { return num > 0; }),
        count_if(nums.begin(), nums.end(), [](int num) { return num < 0; }));
  }
};
