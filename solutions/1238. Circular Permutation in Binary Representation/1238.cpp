class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> ans;

    for (int i = 0; i < 1 << n; ++i)
      ans.push_back(start ^ i ^ i >> 1);

    return ans;
  }
};
