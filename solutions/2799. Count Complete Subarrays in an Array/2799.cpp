class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    constexpr int kMax = 2000;
    const int totalDistinct =
        unordered_set<int>(nums.begin(), nums.end()).size();
    int ans = 0;
    int distinct = 0;
    vector<int> count(kMax + 1);

    int l = 0;
    for (const int num : nums) {
      if (++count[num] == 1)
        ++distinct;
      while (distinct == totalDistinct)
        if (--count[nums[l++]] == 0)
          --distinct;
      // Assume nums[r] = num,
      // nums[0..r], nums[1..r], ..., nums[l - 1..r] have k different values.
      ans += l;
    }

    return ans;
  }
};
