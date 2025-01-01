class Solution {
 public:
  long long shiftDistance(string s, string t, vector<int>& nextCost,
                          vector<int>& previousCost) {
    long ans = 0;
    // prev[i][j] := the prev cost to shift from ('a' + i) to ('a' + j)
    vector<vector<long>> prev(26, vector<long>(26));
    // next[i][j] := the next cost to shift from ('a' + i) to ('a' + j)
    vector<vector<long>> next(26, vector<long>(26));

    for (int i = 0; i < 26; ++i) {
      long cost = 0;
      for (int j = 0; j < 26; ++j) {
        next[i][(i + j) % 26] = cost;
        cost += nextCost[(i + j) % 26];
      }
    }

    for (int i = 0; i < 26; ++i) {
      long cost = 0;
      for (int j = 0; j < 26; ++j) {
        prev[i][(i - j + 26) % 26] = cost;
        cost += previousCost[(i - j + 26) % 26];
      }
    }

    for (int i = 0; i < s.length(); ++i) {
      const int a = s[i] - 'a';
      const int b = t[i] - 'a';
      ans += min(next[a][b], prev[a][b]);
    }

    return ans;
  }
};
