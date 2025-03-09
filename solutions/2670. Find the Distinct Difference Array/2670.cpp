class Solution {
 public:
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    constexpr int kMax = 50;
    vector<int> ans;
    vector<int> prefixCount(kMax + 1);
    vector<int> suffixCount(kMax + 1);
    int distinctPrefix = 0;
    int distinctSuffix = 0;

    for (const int num : nums)
      if (++suffixCount[num] == 1)
        ++distinctSuffix;

    for (const int num : nums) {
      if (++prefixCount[num] == 1)
        ++distinctPrefix;
      if (--suffixCount[num] == 0)
        --distinctSuffix;
      ans.push_back(distinctPrefix - distinctSuffix);
    }

    return ans;
  }
};
