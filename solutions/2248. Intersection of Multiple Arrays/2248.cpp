class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> ans;
    vector<int> count(1001);

    for (const auto& A : nums)
      for (const int a : A)
        ++count[a];

    for (int i = 1; i < 1001; ++i)
      if (count[i] == nums.size())
        ans.push_back(i);

    return ans;
  }
};
