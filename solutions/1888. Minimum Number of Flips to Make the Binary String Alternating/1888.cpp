class Solution {
 public:
  int minFlips(string s) {
    const int n = s.length();
    // count[0][0] := the number of 0s in the even indices
    // count[0][1] := the number of 0s in the odd indices
    // count[1][0] := the number of 1s in the even indices
    // count[1][1] := the number of 1s in the odd indices
    vector<vector<int>> count(2, vector<int>(2));

    for (int i = 0; i < n; ++i)
      ++count[s[i] - '0'][i % 2];

    // min(make all 0s in the even indices + make all 1s in the odd indices,
    //     make all 1s in the even indices + make all 0s in the odd indices)
    int ans = min(count[1][0] + count[0][1], count[0][0] + count[1][1]);

    for (int i = 0; i < n; ++i) {
      --count[s[i] - '0'][i % 2];
      ++count[s[i] - '0'][(n + i) % 2];
      ans = min({ans, count[1][0] + count[0][1], count[0][0] + count[1][1]});
    }

    return ans;
  }
};
