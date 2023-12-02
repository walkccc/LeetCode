class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    vector<int> decreasing(2);

    for (int i = 0; i < nums.size(); ++i) {
      int l = i > 0 ? nums[i - 1] : 1001;
      int r = i + 1 < nums.size() ? nums[i + 1] : 1001;
      decreasing[i % 2] += max(0, nums[i] - min(l, r) + 1);
    }

    return min(decreasing[0], decreasing[1]);
  }
};
