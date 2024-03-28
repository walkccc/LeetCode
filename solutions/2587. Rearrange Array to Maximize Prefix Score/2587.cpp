class Solution {
 public:
  int maxScore(vector<int>& nums) {
    long long prefix = 0;

    ranges::sort(nums, greater<>());

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (prefix <= 0)
        return i;
    }

    return nums.size();
  }
};
