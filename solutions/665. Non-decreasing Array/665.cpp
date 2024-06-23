class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    bool modified = false;

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] < nums[i - 1]) {
        if (modified)
          return false;
        if (i == 1 || nums[i] >= nums[i - 2])
          nums[i - 1] = nums[i];  // Decrease the previous value.
        else
          nums[i] = nums[i - 1];  // Increase the current value.
        modified = true;
      }

    return true;
  }
};
