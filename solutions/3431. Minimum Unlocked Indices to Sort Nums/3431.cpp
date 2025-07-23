class Solution {
 public:
  int minUnlockedIndices(vector<int>& nums, vector<int>& locked) {
    const auto first2It = ranges::find(nums, 2);
    const auto first3It = ranges::find(nums, 3);
    const auto last1It = ranges::find_last(nums, 1);
    const auto last2It = ranges::find_last(nums, 2);
    const int first2 =
        first2It == nums.cend() ? -1 : distance(nums.begin(), first2It);
    const int first3 =
        first3It == nums.cend() ? -1 : distance(nums.begin(), first3It);
    const int last1 = last1It.begin() == nums.cend()
                          ? -1
                          : distance(nums.begin(), last1It.begin());
    const int last2 = last2It.begin() == nums.cend()
                          ? -1
                          : distance(nums.begin(), last2It.begin());
    if (first3 != -1 && last1 != -1 && first3 < last1)
      return -1;

    int ans = 0;

    // Unlocked indices between 2 and 1.
    if (first2 != -1 && last1 != -1)
      for (int i = first2; i < last1; ++i)
        if (locked[i] == 1)
          ++ans;

    // Unlocked indices between 3 and 2.
    if (first3 != -1 && last2 != -1)
      for (int i = first3; i < last2; ++i)
        if (locked[i] == 1)
          ++ans;

    return ans;
  }
};
