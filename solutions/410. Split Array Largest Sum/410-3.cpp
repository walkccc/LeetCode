class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    int l = ranges::max(nums);
    int r = accumulate(nums.begin(), nums.end(), 0) + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (numGroups(nums, m) > k)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }

 private:
  int numGroups(const vector<int>& nums, int maxSumInGroup) {
    int groupCount = 1;
    int sumInGroup = 0;

    for (const int num : nums)
      if (sumInGroup + num <= maxSumInGroup) {
        sumInGroup += num;
      } else {
        ++groupCount;
        sumInGroup = num;
      }

    return groupCount;
  }
};
