class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int start = firstGreaterEqual(nums, target);
    if (start == nums.size() || nums[start] != target)
      return {-1, -1};
    const int end = firstGreaterEqual(nums, target + 1) - 1;
    return {start, end};
  }

 private:
  // find the first index l s.t nums[l] >= target
  // return nums.size() if can'f find
  int firstGreaterEqual(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (nums[m] >= target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
