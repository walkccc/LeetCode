class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    int ans = 0;
    int prevEnd = INT_MIN;

    ranges::sort(pairs,
                 [](const auto& a, const auto& b) { return a[1] < b[1]; });

    for (const vector<int>& pair : pairs)
      if (pair[0] > prevEnd) {
        ++ans;
        prevEnd = pair[1];
      }

    return ans;
  }
};
