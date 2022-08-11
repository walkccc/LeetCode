class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> A;  // indices of '|'

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '|')
        A.push_back(i);

    for (const auto& q : queries) {
      const int left = q[0];
      const int right = q[1];
      const int l = lower_bound(begin(A), end(A), left) - begin(A);
      const int r = upper_bound(begin(A), end(A), right) - begin(A) - 1;
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
