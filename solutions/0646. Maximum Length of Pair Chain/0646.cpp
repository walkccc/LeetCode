class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    int ans = 0;
    int prev = INT_MIN;

    sort(begin(pairs), end(pairs),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    for (const vector<int>& pair : pairs)
      if (pair[0] > prev) {
        ++ans;
        prev = pair[1];
      }

    return ans;
  }
};