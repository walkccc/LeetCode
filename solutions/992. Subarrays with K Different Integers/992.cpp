class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarrayWithAtMostKDistinct(nums, k) -
           subarrayWithAtMostKDistinct(nums, k - 1);
  }

 private:
  int subarrayWithAtMostKDistinct(const vector<int>& nums, int k) {
    int ans = 0;
    vector<int> count(nums.size() + 1);

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (++count[nums[r]] == 1)
        --k;
      while (k == -1)
        if (--count[nums[l++]] == 0)
          ++k;
      ans += r - l + 1;  // nums[l..r], nums[l + 1..r], ..., nums[r]
    }

    return ans;
  }
};
