class Solution {
 public:
  int maxOperations(vector<int>& nums) {
    int ans = 1;
    int sum = nums[0] + nums[1];

    for (int i = 2; i + 1 < nums.size(); i += 2) {
      if (nums[i] + nums[i + 1] == sum)
        ++ans;
      else
        break;
    }

    return ans;
  }
};
