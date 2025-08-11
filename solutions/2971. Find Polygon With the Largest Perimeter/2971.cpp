class Solution {
 public:
  long long largestPerimeter(vector<int>& nums) {
    long prefix = accumulate(nums.begin(), nums.end(), 0L);

    ranges::sort(nums);

    for (int i = nums.size() - 1; i >= 2; --i) {
      prefix -= nums[i];
      // Let nums[i] be the longest side. Check if the sum of all the edges with
      // length no longer than nums[i] > nums[i].
      if (prefix > nums[i])
        return prefix + nums[i];
    }

    return -1;
  }
};
