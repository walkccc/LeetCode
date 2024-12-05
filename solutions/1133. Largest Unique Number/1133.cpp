class Solution {
 public:
  int largestUniqueNumber(vector<int>& nums) {
    constexpr int kMax = 1000;
    vector<short> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int num = kMax; num >= 0; --num)
      if (count[num] == 1)
        return num;

    return -1;
  }
};
