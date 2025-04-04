class Solution {
 public:
  int smallestCommonElement(vector<vector<int>>& mat) {
    constexpr int kMax = 10000;
    vector<int> count(kMax + 1);

    for (const vector<int>& row : mat)
      for (const int a : row)
        if (++count[a] == mat.size())
          return a;

    return -1;
  }
};
