class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysWithAtMostKDistinct(nums, k) -
           subarraysWithAtMostKDistinct(nums, k - 1);
  }

 private:
  int subarraysWithAtMostKDistinct(const vector<int>& nums, int k) {
    int res = 0;
    vector<int> count(nums.size() + 1);

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (++count[nums[r]] == 1)
        --k;
      while (k == -1)
        if (--count[nums[l++]] == 0)
          ++k;
      res += r - l + 1;  // nums[l..r], nums[l + 1..r], ..., nums[r]
    }

    return res;
  }
};
