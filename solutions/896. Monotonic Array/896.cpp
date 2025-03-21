class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); ++i) {
      increasing &= nums[i] >= nums[i - 1];
      decreasing &= nums[i] <= nums[i - 1];
    }

    return increasing || decreasing;
  }
};
