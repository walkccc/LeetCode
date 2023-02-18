class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    int l = *max_element(begin(nums), end(nums));
    int r = accumulate(begin(nums), end(nums), 0) + 1;

    while (l < r) {
      const int mid = (l + r) / 2;
      if (numGroups(nums, mid) > m)
        l = mid + 1;
      else
        r = mid;
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
