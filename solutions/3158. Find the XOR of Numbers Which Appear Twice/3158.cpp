class Solution {
 public:
  int duplicateNumbersXOR(vector<int>& nums) {
    constexpr int kMax = 50;
    int ans = 0;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int num = 1; num <= kMax; ++num)
      if (count[num] == 2)
        ans ^= num;

    return ans;
  }
};
