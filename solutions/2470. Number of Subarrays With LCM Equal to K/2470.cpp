class Solution {
 public:
  int subarrayLCM(vector<int>& nums, int k) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int runningLcm = nums[i];
      for (int j = i; j < nums.size(); ++j) {
        runningLcm = std::lcm(runningLcm, nums[j]);
        if (runningLcm > k)
          break;
        if (runningLcm == k)
          ++ans;
      }
    }

    return ans;
  }
};
