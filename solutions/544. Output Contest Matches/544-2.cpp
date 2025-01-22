class Solution {
 public:
  string findContestMatch(int n) {
    vector<string> matches(n);

    for (int i = 0; i < n; ++i)
      matches[i] = to_string(i + 1);

    while (n > 1) {
      for (int i = 0; i < n / 2; ++i)
        matches[i] = "(" + matches[i] + "," + matches[n - 1 - i] + ")";
      n /= 2;
    }

    return matches[0];
  }
};
