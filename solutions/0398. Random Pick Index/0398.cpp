class Solution {
 public:
  Solution(vector<int>& nums) : nums(move(nums)) {}

  int pick(int target) {
    int ans = -1;
    int range = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == target && rand() % ++range == 0)
        ans = i;

    return ans;
  }

 private:
  vector<int> nums;
};
