class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    constexpr int kMax = 100;
    int ans = 0;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] == 1)
        ans += i;

    return ans;
  }
};
