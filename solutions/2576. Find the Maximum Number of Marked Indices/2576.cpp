class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    ranges::sort(nums);

    int l = 0;
    int r = nums.size() / 2 + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (isPossible(nums, m))
        l = m + 1;
      else
        r = m;
    }

    return (l - 1) * 2;
  }

 private:
  bool isPossible(const vector<int>& nums, int m) {
    for (int i = 0; i < m; ++i)
      if (2 * nums[i] > nums[nums.size() - m + i])
        return false;
    return true;
  }
};
