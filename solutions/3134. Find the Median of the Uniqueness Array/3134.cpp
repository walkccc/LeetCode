class Solution {
 public:
  int medianOfUniquenessArray(vector<int>& nums) {
    const int n = nums.size();
    const long subarryCount = n * (n + 1L) / 2;
    const long medianCount = (subarryCount + 1) / 2;
    int l = 1;
    int r = n;

    while (l < r) {
      const int m = (l + r) / 2;
      if (subarrayWithAtMostKDistinct(nums, m) >= medianCount)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Similar to 992. Subarrays with K Different Integers
  long subarrayWithAtMostKDistinct(const vector<int>& nums, int k) {
    long res = 0;
    unordered_map<int, int> count;

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
