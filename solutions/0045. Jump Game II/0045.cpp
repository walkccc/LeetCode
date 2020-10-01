class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i + 1 < nums.size(); ++i) {
      farthest = max(farthest, i + nums[i]);
      if (i == end) {
        ++ans;
        end = farthest;
      }
    }

    return ans;
  }
};