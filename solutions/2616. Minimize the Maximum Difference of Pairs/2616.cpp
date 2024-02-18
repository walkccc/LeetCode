class Solution {
 public:
  int minimizeMax(vector<int>& nums, int p) {
    ranges::sort(nums);

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      const int m = (l + r) / 2;
      if (numPairs(nums, m) >= p)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns the number of pairs that can be obtained if the difference between
  // each pair <= `maxDiff`.
  int numPairs(const vector<int>& nums, int maxDiff) {
    int pairs = 0;
    for (int i = 1; i < nums.size(); ++i)
      // Greedily pair nums[i] with nums[i - 1].
      if (nums[i] - nums[i - 1] <= maxDiff) {
        ++pairs;
        ++i;
      }
    return pairs;
  }
};
