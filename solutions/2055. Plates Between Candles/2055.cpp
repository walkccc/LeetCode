class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> A;  // Indices of '|'

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '|')
        A.push_back(i);

    for (const vector<int>& query : queries) {
      const int left = query[0];
      const int right = query[1];
      const int l = ranges::lower_bound(A, left) - A.begin();
      const int r = ranges::upper_bound(A, right) - A.begin() - 1;
      if (l < r) {
        const int lengthBetweenCandles = A[r] - A[l] + 1;
        const int numCandles = r - l + 1;
        ans.push_back(lengthBetweenCandles - numCandles);
      } else {
        ans.push_back(0);
      }
    }

    return ans;
  }
};
