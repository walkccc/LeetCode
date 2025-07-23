class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    constexpr int kMax = 1000;
    vector<int> ans;
    vector<int> count(kMax + 1);

    for (const vector<int>& row : nums)
      for (const int a : row)
        ++count[a];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] == nums.size())
        ans.push_back(i);

    return ans;
  }
};
