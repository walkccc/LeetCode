class Solution {
 public:
  vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
    constexpr int kMax = 100;
    vector<int> ans;
    vector<int> count(kMax + 1);

    for (const vector<int>& array : arrays)
      for (const int a : array)
        if (++count[a] == arrays.size())
          ans.push_back(a);

    return ans;
  }
};
