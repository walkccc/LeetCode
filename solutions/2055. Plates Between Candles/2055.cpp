class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> indices;  // indices of '|'

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '|')
        indices.push_back(i);

    for (const vector<int>& query : queries) {
      const int left = query[0];
      const int right = query[1];
      const int l = ranges::lower_bound(indices, left) - indices.begin();
      const int r = ranges::upper_bound(indices, right) - indices.begin() - 1;
      if (l < r) {
        const int lengthBetweenCandles = indices[r] - indices[l] + 1;
        const int numCandles = r - l + 1;
        ans.push_back(lengthBetweenCandles - numCandles);
      } else {
        ans.push_back(0);
      }
    }

    return ans;
  }
};
