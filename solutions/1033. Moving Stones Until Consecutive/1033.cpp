class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> nums = {a, b, c};

    sort(begin(nums), end(nums));

    if (nums[2] - nums[0] == 2)
      return {0, 0};
    return {min(nums[1] - nums[0], nums[2] - nums[1]) <= 2 ? 1 : 2,
            nums[2] - nums[0] - 2};
  }
};
